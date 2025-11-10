// 2025-11-05 12:36:15
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


//You are given an integer mountainHeight denoting the height of a mountain. 
//
// You are also given an integer array workerTimes representing the work time 
//of workers in seconds. 
//
// The workers work simultaneously to reduce the height of the mountain. For 
//worker i: 
//
// 
// To decrease the mountain's height by x, it takes workerTimes[i] + 
//workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example: 
// 
//
// 
// To reduce the height of the mountain by 1, it takes workerTimes[i] seconds. 
// To reduce the height of the mountain by 2, it takes workerTimes[i] + 
//workerTimes[i] * 2 seconds, and so on. 
// 
// 
//
//
// Return an integer representing the minimum number of seconds required for 
//the workers to make the height of the mountain 0. 
//
// 
// Example 1: 
//
// 
// Input: mountainHeight = 4, workerTimes = [2,1,1] 
// 
//
// Output: 3 
//
// Explanation: 
//
// One way the height of the mountain can be reduced to 0 is: 
//
// 
// Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds. 
// Worker 1 reduces the height by 2, taking workerTimes[1] + workerTimes[1] * 2 
//= 3 seconds. 
// Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second. 
// 
//
// Since they work simultaneously, the minimum time needed is max(2, 3, 1) = 3 
//seconds. 
//
// Example 2: 
//
// 
// Input: mountainHeight = 10, workerTimes = [3,2,2,4] 
// 
//
// Output: 12 
//
// Explanation: 
//
// 
// Worker 0 reduces the height by 2, taking workerTimes[0] + workerTimes[0] * 2 
//= 9 seconds. 
// Worker 1 reduces the height by 3, taking workerTimes[1] + workerTimes[1] * 2 
//+ workerTimes[1] * 3 = 12 seconds. 
// Worker 2 reduces the height by 3, taking workerTimes[2] + workerTimes[2] * 2 
//+ workerTimes[2] * 3 = 12 seconds. 
// Worker 3 reduces the height by 2, taking workerTimes[3] + workerTimes[3] * 2 
//= 12 seconds. 
// 
//
// The number of seconds needed is max(9, 12, 12, 12) = 12 seconds. 
//
// Example 3: 
//
// 
// Input: mountainHeight = 5, workerTimes = [1] 
// 
//
// Output: 15 
//
// Explanation: 
//
// There is only one worker in this example, so the answer is workerTimes[0] + 
//workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5
// = 15. 
//
// 
// Constraints: 
//
// 
// 1 <= mountainHeight <= 10⁵ 
// 1 <= workerTimes.length <= 10⁴ 
// 1 <= workerTimes[i] <= 10⁶ 
// 
//
// Related Topics 贪心 数组 数学 二分查找 堆（优先队列） 👍 36 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        if (workerTimes.size() == 1) {
            return 1LL* workerTimes[0] * mountainHeight * (mountainHeight + 1) / 2;
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for (int i = 0; i < workerTimes.size(); i++) {
            pq.push({workerTimes[i], i, 2});
        }

        vector<long long> wasteTimes(workerTimes.size(), 0);
        while (mountainHeight) {
            auto [waste, key, cnt] = pq.top(); pq.pop();
//            cout << "waste = " << waste << ", key = " << key << ", cnt = " << cnt << endl;
            wasteTimes[key] = waste;
            pq.push({wasteTimes[key] + cnt * workerTimes[key], key, cnt + 1});
            mountainHeight--;
        }

        return *max_element(wasteTimes.begin(), wasteTimes.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)
