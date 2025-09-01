// 2025-08-28 00:14:44
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given an n x n square matrix of integers grid. Return the matrix such 
//that: 
//
// 
// The diagonals in the bottom-left triangle (including the middle diagonal) 
//are sorted in non-increasing order. 
// The diagonals in the top-right triangle are sorted in non-decreasing order. 
// 
//
// 
// Example 1: 
//
// 
// Input: grid = [[1,7,3],[9,8,2],[4,5,6]] 
// 
//
// Output: [[8,2,3],[9,6,7],[4,5,1]] 
//
// Explanation: 
//
// 
//
// The diagonals with a black arrow (bottom-left triangle) should be sorted in 
//non-increasing order: 
//
// 
// [1, 8, 6] becomes [8, 6, 1]. 
// [9, 5] and [4] remain unchanged. 
// 
//
// The diagonals with a blue arrow (top-right triangle) should be sorted in non-
//decreasing order: 
//
// 
// [7, 2] becomes [2, 7]. 
// [3] remains unchanged. 
// 
//
// Example 2: 
//
// 
// Input: grid = [[0,1],[1,2]] 
// 
//
// Output: [[2,1],[1,0]] 
//
// Explanation: 
//
// 
//
// The diagonals with a black arrow must be non-increasing, so [0, 2] is 
//changed to [2, 0]. The other diagonals are already in the correct order. 
//
// Example 3: 
//
// 
// Input: grid = [[1]] 
// 
//
// Output: [[1]] 
//
// Explanation: 
//
// Diagonals with exactly one element are already in order, so no changes are 
//needed. 
//
// 
// Constraints: 
//
// 
// grid.length == grid[i].length == n 
// 1 <= n <= 10 
// -10⁵ <= grid[i][j] <= 10⁵ 
// 
//
// Related Topics 数组 矩阵 排序 👍 11 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid;

        auto legal = [n](int r, int c) { return 0 <= r && r < n && 0 <= c && c < n; };
        auto process = [&](vector<pair<int, int>> starts, bool reverse) {
            for (auto [x, y] : starts) {
                vector<int> diagonal;
                int tx = x, ty = y;
                while (legal(tx, ty)) diagonal.push_back(grid[tx++][ty++]);

                if (!reverse) sort(diagonal.begin(), diagonal.end());
                else sort(diagonal.rbegin(), diagonal.rend());

                tx = x, ty = y;
                for (int val : diagonal) grid[tx++][ty++] = val;
            }
        };

        // 处理右上角对角线（升序）
        vector<pair<int, int>> starts1;
        for (int j = n - 1; j > 0; j--) starts1.emplace_back(0, j);
        process(starts1, false);

        // 处理左下角对角线（降序）
        vector<pair<int, int>> starts2;
        for (int i = 0; i < n; i++) starts2.emplace_back(i, 0);
        process(starts2, true);

        return grid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//int main() {
//    vector<vector<int>> nums = {{1,7,3},{9,8,2},{4,5,6}};
//    Solution().sortMatrix(nums);
//}