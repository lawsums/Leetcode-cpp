// 2025-11-05 13:09:12
#include <bits/stdc++.h>
#include <DisplayHelper.h>
#include <Heap.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//There is a party where n friends numbered from 0 to n - 1 are attending. 
//There is an infinite number of chairs in this party that are numbered from 0 to 
//infinity. When a friend arrives at the party, they sit on the unoccupied chair with 
//the smallest number. 
//
// 
// For example, if chairs 0, 1, and 5 are occupied when a friend comes, they 
//will sit on chair number 2. 
// 
//
// When a friend leaves the party, their chair becomes unoccupied at the moment 
//they leave. If another friend arrives at that same moment, they can sit in that 
//chair. 
//
// You are given a 0-indexed 2D integer array times where times[i] = [arrivali, 
//leavingi], indicating the arrival and leaving times of the iᵗʰ friend 
//respectively, and an integer targetFriend. All arrival times are distinct. 
//
// Return the chair number that the friend numbered targetFriend will sit on. 
//
// 
// Example 1: 
//
// 
//Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
//Output: 1
//Explanation: 
//- Friend 0 arrives at time 1 and sits on chair 0.
//- Friend 1 arrives at time 2 and sits on chair 1.
//- Friend 1 leaves at time 3 and chair 1 becomes empty.
//- Friend 0 leaves at time 4 and chair 0 becomes empty.
//- Friend 2 arrives at time 4 and sits on chair 0.
//Since friend 1 sat on chair 1, we return 1.
// 
//
// Example 2: 
//
// 
//Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
//Output: 2
//Explanation: 
//- Friend 1 arrives at time 1 and sits on chair 0.
//- Friend 2 arrives at time 2 and sits on chair 1.
//- Friend 0 arrives at time 3 and sits on chair 2.
//- Friend 1 leaves at time 5 and chair 0 becomes empty.
//- Friend 2 leaves at time 6 and chair 1 becomes empty.
//- Friend 0 leaves at time 10 and chair 2 becomes empty.
//Since friend 0 sat on chair 2, we return 2.
// 
//
// 
// Constraints: 
//
// 
// n == times.length 
// 2 <= n <= 10⁴ 
// times[i].length == 2 
// 1 <= arrivali < leavingi <= 10⁵ 
// 0 <= targetFriend <= n - 1 
// Each arrivali time is distinct. 
// 
//
// Related Topics 数组 哈希表 堆（优先队列） 👍 59 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
typedef tuple<int, int, int> tt;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });

        // 建立一个结束时间最小堆
        auto cmp = [](tt& a, tt& b) {
            return get<1>(a) > get<1>(b);
        };
        priority_queue<tt, vector<tt>, decltype(cmp)> pq(cmp);
        // 空闲座位表
        priority_queue<int, vector<int>, greater<int>> spare_seats;
        int res_id = 0;

        for (int i = 0, spare_id = 0; i < times.size(); i++) {
            auto chosen = times[indices[i]];
            print_fmt("i = {0}, chosen = {1}", i, chosen);

            while (!pq.empty() && get<1>(pq.top()) <= chosen[0]) {
                auto seat_id = get<2>(pq.top());
                pq.pop(); // 弹出当前座位
                spare_seats.push(seat_id);
            }

            if (!spare_seats.empty()) { // 如果有剩余的最小id
                spare_id = spare_seats.top();
                print_fmt("\thave spare_seats: {0}", spare_id);
                spare_seats.pop();
            } else { // 如果没有就是从无限座位集里面取
                spare_id = res_id++;
                print_fmt("\tnot spare_seats: {0}, res_id: {1}", spare_id, res_id);
            }
            if (indices[i] == targetFriend) { // 如果找到了直接返回答案
                return spare_id;
            }
            pq.push({chosen[0], chosen[1], spare_id});

        }

        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> times = {{1,4},{2,3},{4,6}};
    int targetFriend = 1;
    cout << Solution().smallestChair(times, targetFriend) << endl;

    times = {{3,10},{1,5},{2,6}};
    targetFriend = 0;
    cout << Solution().smallestChair(times, targetFriend) << endl;

    cout << "[[3]]" << endl;
    times = {{33,35},{26,29},{9,28},{4,31},{8,10},{32,34},{15,24},{27,39},{14,36},{1,14},{25,39},{5,27},{6,15},{2,38},{19,36},{24,34},{3,26}};
    targetFriend = 0;
    cout << Solution().smallestChair(times, targetFriend) << endl;

}