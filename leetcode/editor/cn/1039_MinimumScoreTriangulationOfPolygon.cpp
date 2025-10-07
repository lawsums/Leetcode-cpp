// 2025-09-29 01:38:46
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You have a convex n-sided polygon where each vertex has an integer value. You 
//are given an integer array values where values[i] is the value of the iᵗʰ 
//vertex in clockwise order. 
//
// Polygon triangulation is a process where you divide a polygon into a set of 
//triangles and the vertices of each triangle must also be vertices of the 
//original polygon. Note that no other shapes other than triangles are allowed in the 
//division. This process will result in n - 2 triangles. 
//
// You will triangulate the polygon. For each triangle, the weight of that 
//triangle is the product of the values at its vertices. The total score of the 
//triangulation is the sum of these weights over all n - 2 triangles. 
//
// Return the minimum possible score that you can achieve with some 
//triangulation of the polygon. 
//
// 
// Example 1: 
//
// 
//
// 
// Input: values = [1,2,3] 
// 
//
// Output: 6 
//
// Explanation: The polygon is already triangulated, and the score of the only 
//triangle is 6. 
//
// Example 2: 
//
// 
//
// 
// Input: values = [3,7,4,5] 
// 
//
// Output: 144 
//
// Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*
//7 = 245, or 3*4*5 + 3*4*7 = 144. The minimum score is 144. 
//
// Example 3: 
//
// 
//
// 
// Input: values = [1,3,1,4,1,5] 
// 
//
// Output: 13 
//
// Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1
// = 13. 
//
// 
// Constraints: 
//
// 
// n == values.length 
// 3 <= n <= 50 
// 1 <= values[i] <= 100 
// 
//
// Related Topics 数组 动态规划 👍 320 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        return f1(values);
    }

    int f1(vector<int>& values) { // 区间dp
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 区间长度从3开始（三角形）
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // 枚举分割点k，将多边形[i,j]分割为[i,k]和[k,j]两个部分
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }

        return dp[0][n - 1];
    }

    int f2(vector<int>& values) {
        if (values.size() == 3) return values[0] * values[1] * values[2];

        int ans  = 0;
        while (values.size() > 3) {
            int mmin = INT_MAX, abs_min = INT_MIN, id_delete = -1;
            int n = values.size();
            for (int i = 0; i < n; i++) {
                int tmp = values[i] * values[(i + 2) % n];
                int _abs = abs(values[i] - values[(i + 2) % n]);
                if (tmp < mmin || (tmp == mmin && _abs > abs_min /* 留着极差大的 */)) {
                    mmin = tmp;
                    abs_min = _abs;
                    id_delete = (i + 1) % n;
                }
            }
            ans += mmin * values[id_delete];
            values.erase(values.begin() + id_delete);
        }

        return ans + values[0] * values[1] * values[2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> values = {3,3,6,2,1,4};
    auto ans = Solution().minScoreTriangulation(values);
    print(ans);
}