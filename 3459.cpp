// 2025-08-27 09:05:36
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//给你一个大小为 n x m 的二维整数矩阵 grid，其中每个元素的值为 0、1 或 2。
//
// V 形对角线段 定义如下：
//
//
// 线段从 1 开始。
// 后续元素按照以下无限序列的模式排列：2, 0, 2, 0, ...。
// 该线段：
//
// 起始于某个对角方向（左上到右下、右下到左上、右上到左下或左下到右上）。
// 沿着相同的对角方向继续，保持 序列模式 。
// 在保持 序列模式 的前提下，最多允许 一次顺时针 90 度转向 另一个对角方向。
//
//
//
//
//
// 返回最长的 V 形对角线段 的 长度 。如果不存在有效的线段，则返回 0。
//
//
//
// 示例 1：
//
//
// 输入： grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
//
//
// 输出： 5
//
// 解释：
//
//
//
// 最长的 V 形对角线段长度为 5，路径如下：(0,2) → (1,3) → (2,4)，在 (2,4) 处进行 顺时针 90 度转向 ，继续路径为 (3,
//3) → (4,2)。
//
// 示例 2：
//
//
// 输入： grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
//
//
// 输出： 4
//
// 解释：
//
//
//
// 最长的 V 形对角线段长度为 4，路径如下：(2,3) → (3,2)，在 (3,2) 处进行 顺时针 90 度转向 ，继续路径为 (2,1) → (1,
//0)。
//
// 示例 3：
//
//
// 输入： grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]
//
//
// 输出： 5
//
// 解释：
//
//
//
// 最长的 V 形对角线段长度为 5，路径如下：(0,0) → (1,1) → (2,2) → (3,3) → (4,4)。
//
// 示例 4：
//
//
// 输入： grid = [[1]]
//
//
// 输出： 1
//
// 解释：
//
// 最长的 V 形对角线段长度为 1，路径如下：(0,0)。
//
//
//
// 提示：
//
//
// n == grid.length
// m == grid[i].length
// 1 <= n, m <= 500
// grid[i][j] 的值为 0、1 或 2。
//
//
// Related Topics 记忆化搜索 数组 动态规划 矩阵 👍 6 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> move{-1, 1, 1, -1, -1};
    int n, m;
public:
    int dfs(int r, int c, int direc, int step, vector<vector<int>>& grid) {
        // 边界条件退出
        if (r < 0 || r >= n || c < 0 || c >= m) return 0;
        if (!(step & 1) && (grid[r][c] != 2)) return 0; // step 为偶数时,grid[r][c]必须为2
        if ((step & 1) && (grid[r][c] != 0)) return 0; // step 为奇数时,grid[r][c]必须为0

        int origin_ = dfs(r + move[direc], c + move[direc + 1], direc, step + 1, grid);
        direc = (direc + 1) % 4;
        int rotate_ = dfs(r + move[direc], c + move[direc + 1], direc, step + 1, grid);
        direc = (direc - 1 + 4) % 4;
        return max(origin_, rotate_) + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { // 如果此时为一,则朝四个方向开始dfs
                    for (int k = 0; k < 4; k++) {
                        ans = max(ans, dfs(i + move[k], j + move[k + 1], k, 0, grid) + 1);
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> nums = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    Solution().lenOfVDiagonal(nums);
}