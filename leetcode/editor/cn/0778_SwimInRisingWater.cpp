// 2025-10-06 01:05:09
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given an n x n integer matrix grid where each value grid[i][j] 
//represents the elevation at that point (i, j). 
//
// It starts raining, and water gradually rises over time. At time t, the water 
//level is t, meaning any cell with elevation less than equal to t is submerged 
//or reachable. 
//
// You can swim from a square to another 4-directionally adjacent square if and 
//only if the elevation of both squares individually are at most t. You can swim 
//infinite distances in zero time. Of course, you must stay within the boundaries 
//of the grid during your swim. 
//
// Return the minimum time until you can reach the bottom right square (n - 1, 
//n - 1) if you start at the top left square (0, 0). 
//
// 
// Example 1: 
// 
// 
//Input: grid = [[0,2],[1,3]]
//Output: 3
//Explanation:
//At time 0, you are in grid location (0, 0).
//You cannot go anywhere else because 4-directionally adjacent neighbors have a 
//higher elevation than t = 0.
//You cannot reach point (1, 1) until time 3.
//When the depth of water is 3, we can swim anywhere inside the grid.
// 
//
// Example 2: 
// 
// 
//Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[
//10,9,8,7,6]]
//Output: 16
//Explanation: The final route is shown.
//We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
// 
//
// 
// Constraints: 
//
// 
// n == grid.length 
// n == grid[i].length 
// 1 <= n <= 50 
// 0 <= grid[i][j] < n² 
// Each value grid[i][j] is unique. 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 二分查找 矩阵 堆（优先队列） 👍 335 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// class Solution {
// private:
//     vector<int> mode = {-1, 0, 1, 0, -1};
//     vector<vector<bool>> visited;
//     int n, m;

// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         this->n = grid.size(), this->m = grid[0].size();
//         int ans = -1;
//         int l = 0, r = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 r = max(r, grid[i][j]);
//             }
//         }

//         while (l <= r) {
//             int mid = l + (r - l) / 2;  // 避免变量名冲突
//             if (check(grid, mid)) {
//                 r = mid - 1;
//                 ans = mid;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return ans;
//     }

//     bool check(vector<vector<int>>& grid, int wh) {
//         visited.assign(n, vector<bool>(m, false));

//         auto legal = [&](int r, int c) {
//             return 0 <= r && r < n && 0 <= c && c < m;
//         };

//         // 检查起点水位
//         if (grid[0][0] > wh) return false;

//         queue<pair<int, int>> q;  // 简化队列，不需要存储值
//         q.push({0, 0});
//         visited[0][0] = true;  // 入队时标记

//         while (!q.empty()) {
//             auto [r, c] = q.front(); q.pop();

//             // 提前终止
//             if (r == n - 1 && c == m - 1) return true;

//             for (int k = 0; k < 4; k++) {
//                 int nr = r + mode[k];
//                 int nc = c + mode[k + 1];

//                 if (legal(nr, nc) && !visited[nr][nc] && grid[nr][nc] <= wh) {
//                     visited[nr][nc] = true;  // 入队时标记
//                     q.push({nr, nc});
//                 }
//             }
//         }

//         return visited[n - 1][m - 1];
//     }
// };


class Solution {
private:
    vector<int> dirs = {-1, 0, 1, 0, -1};  // 方向数组
    vector<vector<int>> timestamp;          // 时间戳数组
    int current_time = 0;                   // 当前时间戳
    int n, m;

public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        timestamp.assign(n, vector<int>(m, 0));  // 初始化时间戳数组

        // 确定二分范围
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r = max(r, grid[i][j]);
            }
        }

        int ans = -1;
        // 二分查找最小水位
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canReach(grid, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canReach(vector<vector<int>>& grid, int water_level) {
        current_time++;  // 新的时间戳，相当于"逻辑重置"visited数组

        // 起点水位检查
        if (grid[0][0] > water_level) {
            return false;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        timestamp[0][0] = current_time;  // 标记起点为当前时间访问

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            // 到达终点
            if (r == n - 1 && c == m - 1) {
                return true;
            }

            // 四个方向探索
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k];
                int nc = c + dirs[k + 1];

                // 检查边界、时间戳和水位
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    timestamp[nr][nc] != current_time &&  // 关键：时间戳检查
                    grid[nr][nc] <= water_level) {

                    timestamp[nr][nc] = current_time;  // 标记为当前时间访问
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
