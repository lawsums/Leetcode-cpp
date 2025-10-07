// 2025-09-25 09:50:18
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given a triangle array, return the minimum path sum from top to bottom. 
//
// For each step, you may move to an adjacent number of the row below. More 
//formally, if you are on index i on the current row, you may move to either index i 
//or index i + 1 on the next row. 
//
// 
// Example 1: 
//
// 
//Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//Output: 11
//Explanation: The triangle looks like:
//   2
//  3 4
// 6 5 7
//4 1 8 3
//The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined 
//above).
// 
//
// Example 2: 
//
// 
//Input: triangle = [[-10]]
//Output: -10
// 
//
// 
// Constraints: 
//
// 
// 1 <= triangle.length <= 200 
// triangle[0].length == 1 
// triangle[i].length == triangle[i - 1].length + 1 
// -10⁴ <= triangle[i][j] <= 10⁴ 
// 
//
// 
//Follow up: Could you do this using only 
//O(n) extra space, where 
//n is the total number of rows in the triangle?
//
// Related Topics 数组 动态规划 👍 1475 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> ans;
        for (int i = 0; i < triangle.size() - 1; i++) {
            ans.push_back(vector<int>(triangle[i].size(), INT_MAX));
        }
        ans.push_back(vector<int>(triangle.back().begin(), triangle.back().end()));

        for (int i = triangle.size() - 1; i > 0; i--) {
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                ans[i - 1][j] = min(ans[i - 1][j], ans[i][j] + triangle[i - 1][j]);
                ans[i - 1][j - 1] = min(ans[i - 1][j - 1], ans[i][j] + triangle[i - 1][j - 1]);
            }
            ans[i - 1][0] = min(ans[i - 1][0], ans[i][0] + triangle[i - 1][0]);
            ans[i - 1].back() = min(ans[i - 1].back(), ans[i].back() + triangle[i - 1].back());
        }

        return ans[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
