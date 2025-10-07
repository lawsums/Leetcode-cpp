// 2025-09-06 15:37:28
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given an array of intervals where intervals[i] = [starti, endi], merge all 
//overlapping intervals, and return an array of the non-overlapping intervals that 
//cover all the intervals in the input. 
//
// 
// Example 1: 
//
// 
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// 
//
// Example 2: 
//
// 
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// 
//
// Example 3: 
//
// 
//Input: intervals = [[4,7],[1,4]]
//Output: [[1,7]]
//Explanation: Intervals [1,4] and [4,7] are considered overlapping.
// 
//
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
//
// Related Topics 数组 排序 👍 2634 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
#include <ranges>
#include <queue>

// 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res{intervals.front()};
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res.back()[1])
                res.back()[1]=max(intervals[i][1],res.back()[1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

// 2
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        unordered_map<int, int> ends;
        ranges::sort(intervals, [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        auto cmp = [](int a, int b) { return a < b; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        auto start = intervals[0][0];
        pq.push(intervals[0][1]);
        ends[start] = pq.top();

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= pq.top()) {
                pq.push(intervals[i][1]);
            } else {
                start = intervals[i][0];
                while (!pq.empty()) pq.pop();
                pq.push(intervals[i][1]);
            }
            ends[start] = pq.top();
        }

        vector<vector<int>> ans;
        for (const auto& [start_, end_] : ends) {
            ans.push_back({start_, end_});
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
