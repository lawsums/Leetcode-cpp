// 2025-09-16 14:11:19
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//You are given an array of events where events[i] = [startDayi, endDayi]. 
//Every event i starts at startDayi and ends at endDayi. 
//
// You can attend an event i at any day d where startDayi <= d <= endDayi. You 
//can only attend one event at any time d. 
//
// Return the maximum number of events you can attend. 
//
// 
// Example 1: 
// 
// 
//Input: events = [[1,2],[2,3],[3,4]]
//Output: 3
//Explanation: You can attend all the three events.
//One way to attend them all is as shown.
//Attend the first event on day 1.
//Attend the second event on day 2.
//Attend the third event on day 3.
// 
//
// Example 2: 
//
// 
//Input: events= [[1,2],[2,3],[3,4],[1,2]]
//Output: 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= events.length <= 10⁵ 
// events[i].length == 2 
// 1 <= startDayi <= endDayi <= 10⁵ 
// 
//
// Related Topics 贪心 数组 排序 堆（优先队列） 👍 344 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <queue>
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ranges::sort(events, [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        auto cmp = [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; };
        // 小根堆比较器

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int startT = events.front()[0],
            endT = (*max_element(events.begin(), events.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; }))[1];
        int ans = 0;
        for (int cur = startT, idx = 0; cur <= endT; cur++) {
            while (idx < events.size() && events[idx][0] <= cur) { // 入队
                pq.push(events[idx]);
                idx++; // 迭代
            }
            while (!pq.empty() && pq.top()[1] < cur) { // 过期了需要丢掉
                pq.pop();
            }
            if (!pq.empty()) { // 每个时间只能参加一个会议
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
