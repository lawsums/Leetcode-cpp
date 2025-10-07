// 2025-09-20 09:30:53
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Design a data structure that can efficiently manage data packets in a network 
//router. Each data packet consists of the following attributes: 
//
// 
// source: A unique identifier for the machine that generated the packet. 
// destination: A unique identifier for the target machine. 
// timestamp: The time at which the packet arrived at the router. 
// 
//
// Implement the Router class: 
//
// Router(int memoryLimit): Initializes the Router object with a fixed memory 
//limit. 
//
// 
// memoryLimit is the maximum number of packets the router can store at any 
//given time. 
// If adding a new packet would exceed this limit, the oldest packet must be 
//removed to free up space. 
// 
//
// bool addPacket(int source, int destination, int timestamp): Adds a packet 
//with the given attributes to the router. 
//
// 
// A packet is considered a duplicate if another packet with the same source, 
//destination, and timestamp already exists in the router. 
// Return true if the packet is successfully added (i.e., it is not a duplicate)
//; otherwise return false. 
// 
//
// int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) 
//order. 
//
// 
// Remove the packet from storage. 
// Return the packet as an array [source, destination, timestamp]. 
// If there are no packets to forward, return an empty array. 
// 
//
// int getCount(int destination, int startTime, int endTime): 
//
// 
// Returns the number of packets currently stored in the router (i.e., not yet 
//forwarded) that have the specified destination and have timestamps in the 
//inclusive range [startTime, endTime]. 
// 
//
// Note that queries for addPacket will be made in increasing order of 
//timestamp. 
//
// 
// Example 1: 
//
// 
// Input: ["Router", "addPacket", "addPacket", "addPacket", "addPacket", 
//"addPacket", "forwardPacket", "addPacket", "getCount"] [[3], [1, 4, 90], [2, 5, 90], [1
//, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]] 
// 
//
// Output: [null, true, true, false, true, true, [2, 5, 90], true, 1] 
//
// Explanation Router router = new Router(3); // Initialize Router with 
//memoryLimit of 3.
// router.addPacket(1, 4, 90); // Packet is added. Return True.
// router.addPacket(2, 5, 90); // Packet is added. Return True.
// router.addPacket(1, 4, 90); // This is a duplicate packet. Return False.
// router.addPacket(3, 5, 95); // Packet is added. Return True
// router.addPacket(4, 5, 105); // Packet is added, 
//[1, 4, 90] is removed as number of packets exceeds memoryLimit. Return True.
// router.forwardPacket(); // Return 
//[2, 5, 90] and remove it from router.
// router.addPacket(5, 2, 110); // Packet is added. Return True.
// router.getCount(5, 100, 110); // The only packet with destination 5 and 
//timestamp in the inclusive range 
//[100, 110] is 
//[4, 5, 105]. Return 1.
//
// Example 2: 
//
// 
// Input: ["Router", "addPacket", "forwardPacket", "forwardPacket"] [[2], [7, 4,
// 90], [], []] 
// 
//
// Output: [null, true, [7, 4, 90], []] 
//
// Explanation Router router = new Router(2); // Initialize 
//Router with 
//memoryLimit of 2.
// router.addPacket(7, 4, 90); // Return True.
// router.forwardPacket(); // Return 
//[7, 4, 90].
// router.forwardPacket(); // There are no packets left, return 
//[].
//
// 
// Constraints: 
//
// 
// 2 <= memoryLimit <= 10⁵ 
// 1 <= source, destination <= 2 * 10⁵ 
// 1 <= timestamp <= 10⁹ 
// 1 <= startTime <= endTime <= 10⁹ 
// At most 10⁵ calls will be made to addPacket, forwardPacket, and getCount 
//methods altogether. 
// queries for addPacket will be made in increasing order of timestamp. 
// 
//
// Related Topics 设计 队列 数组 哈希表 二分查找 有序集合 👍 15 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <tuple>
#include <queue>
#include <deque>
#include <set>

class Router {
private:
    int memoryLimit;
    queue<tuple<int, int, int>> q;
    unordered_map<int, multiset<int>> mp; // 改为 multiset 允许重复时间戳
    set<tuple<int, int, int>> packetSet; // 用于检测重复包

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        auto packet = make_tuple(source, destination, timestamp);
        if (packetSet.find(packet) != packetSet.end()) {
            return false;
        }

        q.push(packet);
        mp[destination].insert(timestamp);
        packetSet.insert(packet);

        if (q.size() > memoryLimit) {
            auto [s, d, t] = q.front();
            q.pop();

            // 从 multiset 中删除一个时间戳（可能有多个相同的）
            auto it = mp[d].find(t);
            if (it != mp[d].end()) {
                mp[d].erase(it);
                if (mp[d].empty()) {
                    mp.erase(d);
                }
            }

            packetSet.erase({s, d, t});
        }

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto [s, d, t] = q.front();
        q.pop();

        // 从 multiset 中删除一个时间戳
        auto it = mp[d].find(t);
        if (it != mp[d].end()) {
            mp[d].erase(it);
            if (mp[d].empty()) {
                mp.erase(d);
            }
        }

        packetSet.erase({s, d, t});

        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (mp.find(destination) == mp.end()) {
            return 0;
        }

        const auto& timestamps = mp[destination];
        auto startIt = timestamps.lower_bound(startTime);
        auto endIt = timestamps.upper_bound(endTime);

        return distance(startIt, endIt);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
//leetcode submit region end(Prohibit modification and deletion)
