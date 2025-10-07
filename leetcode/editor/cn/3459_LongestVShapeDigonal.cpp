// 2025-08-27 09:05:36
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
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
// 记忆化搜索
class Solution {
    static constexpr int DIRS[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector<array<array<int, 2>, 4>>(n)); // 嵌套四层矩阵，里面两层使用array因为一个表示方向，一个表示机会，都是确定的大小

        // 上一步在 (i,j)，移动方向为 DIRS[k]，是否可以右转，当前位置目标值
        auto dfs = [&](this auto&& dfs, int i, int j, int k, bool can_turn, int target) -> int { // 这里写成lambda表达式有什么好处?
            i += DIRS[k][0];
            j += DIRS[k][1];
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target) {
                return 0;
            }
            int& res = memo[i][j][k][can_turn]; // 注意这里是引用
            if (res) { // 之前计算过
                return res;
            }
            res = dfs(i, j, k, can_turn, 2 - target) + 1; // 直行
            if (can_turn) {
                res = max(res, dfs(i, j, (k + 1) % 4, false, 2 - target) + 1); // 右转
            }
            return res;
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) { // 枚举起始方向
                        ans = max(ans, dfs(i, j, k, true, 2) + 1);
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
