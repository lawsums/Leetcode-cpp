// 2025-09-27 00:42:38
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 数组 动态规划 👍 186 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
        dp[0] = costs[0];

        for (int i = 1; i < costs.size(); i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};
    cout << Solution().minCost(costs) << endl;
}