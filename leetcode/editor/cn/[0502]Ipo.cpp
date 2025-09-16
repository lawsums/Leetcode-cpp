// 2025-09-16 14:51:46
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Suppose LeetCode will start its IPO soon. In order to sell a good price of 
//its shares to Venture Capital, LeetCode would like to work on some projects to 
//increase its capital before the IPO. Since it has limited resources, it can only 
//finish at most k distinct projects before the IPO. Help LeetCode design the best 
//way to maximize its total capital after finishing at most k distinct projects. 
//
// You are given n projects where the iᵗʰ project has a pure profit profits[i] 
//and a minimum capital of capital[i] is needed to start it. 
//
// Initially, you have w capital. When you finish a project, you will obtain 
//its pure profit and the profit will be added to your total capital. 
//
// Pick a list of at most k distinct projects from given projects to maximize 
//your final capital, and return the final maximized capital. 
//
// The answer is guaranteed to fit in a 32-bit signed integer. 
//
// 
// Example 1: 
//
// 
//Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
//Output: 4
//Explanation: Since your initial capital is 0, you can only start the project 
//indexed 0.
//After finishing it you will obtain profit 1 and your capital becomes 1.
//With capital 1, you can either start the project indexed 1 or the project 
//indexed 2.
//Since you can choose at most 2 projects, you need to finish the project 
//indexed 2 to get the maximum capital.
//Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
// 
//
// Example 2: 
//
// 
//Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
//Output: 6
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= 10⁵ 
// 0 <= w <= 10⁹ 
// n == profits.length 
// n == capital.length 
// 1 <= n <= 10⁵ 
// 0 <= profits[i] <= 10⁴ 
// 0 <= capital[i] <= 10⁹ 
// 
//
// Related Topics 贪心 数组 排序 堆（优先队列） 👍 365 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <queue>
class Solution {
public:
    /*
     * k: 可以选的任务数
     * w: 初始资本
     */
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return f2(k, w, profits, capital);
    }

    int f1(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> costs_profits;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            costs_profits.push_back({capital[i], profits[i]});
        } // 加入一个数组方便一起排序
        ranges::sort(costs_profits, [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; }); // 按任务成本升序排序
        // 排序完毕

        auto cmp = [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> locked(cmp);
        // 大根堆

        int cur = w; // 初始资金
        for (int idx = 0; k; k--) { // 拿k个任务
            while (idx < n /* 加入边界条件限制 */ && costs_profits[idx][0] <= cur) {
                locked.push(costs_profits[idx]);
                idx++;
            }
            if (!locked.empty()) {
                cur += locked.top()[1];
                locked.pop();
            } // 每次执行一个利润最高的任务
        }

        return cur;
    }

    int f2(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects; // 使用pair而不是vector<int>

        for (int i = 0; i < n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // 按资本要求排序
        sort(projects.begin(), projects.end());

        // 大顶堆：存储可执行项目的利润
        priority_queue<int> maxHeap;

        int idx = 0;
        int currentCapital = w;

        for (int i = 0; i < k; i++) {
            // 将所有当前资本可以执行的项目加入堆
            while (idx < n && projects[idx].first <= currentCapital) {
                maxHeap.push(projects[idx].second);
                idx++;
            }

            // 如果没有可执行的项目，提前结束
            if (maxHeap.empty()) {
                break;
            }

            // 选择利润最大的项目执行
            currentCapital += maxHeap.top();
            maxHeap.pop();
        }

        return currentCapital;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
