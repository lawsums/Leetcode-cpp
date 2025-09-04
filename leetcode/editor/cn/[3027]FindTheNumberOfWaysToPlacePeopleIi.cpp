// 2025-09-03 16:31:02
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given a 2D array points of size n x 2 representing integer 
//coordinates of some points on a 2D-plane, where points[i] = [xi, yi]. 
//
// We define the right direction as positive x-axis (increasing x-coordinate) 
//and the left direction as negative x-axis (decreasing x-coordinate). Similarly, 
//we define the up direction as positive y-axis (increasing y-coordinate) and the 
//down direction as negative y-axis (decreasing y-coordinate) 
//
// You have to place n people, including Alice and Bob, at these points such 
//that there is exactly one person at every point. Alice wants to be alone with Bob, 
//so Alice will build a rectangular fence with Alice's position as the upper left 
//corner and Bob's position as the lower right corner of the fence (Note that the 
//fence might not enclose any area, i.e. it can be a line). If any person other 
//than Alice and Bob is either inside the fence or on the fence, Alice will be sad. 
//
//
// Return the number of pairs of points where you can place Alice and Bob, such 
//that Alice does not become sad on building the fence. 
//
// Note that Alice can only build a fence with Alice's position as the upper 
//left corner, and Bob's position as the lower right corner. For example, Alice 
//cannot build either of the fences in the picture below with four corners (1, 1), (1, 
//3), (3, 1), and (3, 3), because: 
//
// 
// With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper 
//left corner and Bob's position is not the lower right corner of the fence. 
// With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower 
//right corner of the fence. 
// 
// 
// 
// Example 1: 
// 
// 
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 0
//Explanation: There is no way to place Alice and Bob such that Alice can build 
//a fence with Alice's position as the upper left corner and Bob's position as 
//the lower right corner. Hence we return 0. 
// 
//
// Example 2: 
// 
// 
//Input: points = [[6,2],[4,4],[2,6]]
//Output: 2
//Explanation: There are two ways to place Alice and Bob such that Alice will 
//not be sad:
//- Place Alice at (4, 4) and Bob at (6, 2).
//- Place Alice at (2, 6) and Bob at (4, 4).
//You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4
//) will be inside the fence.
// 
//
// Example 3: 
// 
// 
//Input: points = [[3,1],[1,3],[1,1]]
//Output: 2
//Explanation: There are two ways to place Alice and Bob such that Alice will 
//not be sad:
//- Place Alice at (1, 1) and Bob at (3, 1).
//- Place Alice at (1, 3) and Bob at (1, 1).
//You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1
//) will be on the fence.
//Note that it does not matter if the fence encloses any area, the first and 
//second fences in the image are valid.
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 1000 
// points[i].length == 2 
// -10⁹ <= points[i][0], points[i][1] <= 10⁹ 
// All points[i] are distinct. 
// 
//
// Related Topics 几何 数组 数学 枚举 排序 👍 20 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> pre;

public:
    int numberOfPairs(vector<vector<int>>& points) {
        // 得出离散化的unique列表
        vector<int> x_list, y_list;
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            x_list.push_back(x);
            y_list.push_back(y);
        }
        ranges::sort(x_list);
        ranges::sort(y_list);
        x_list.erase(unique(x_list.begin(), x_list.end()), x_list.end());
        y_list.erase(unique(y_list.begin(), y_list.end()), y_list.end());

        // 构建二维前缀和
        pre.assign(x_list.size(), vector<int>(y_list.size(), 0));
        for (const auto& point : points) {
            int x = point[0], y = point[1];
            int ix = lower_bound(x_list.begin(), x_list.end(), x) - x_list.begin();
            int iy = lower_bound(y_list.begin(), y_list.end(), y) - y_list.begin();
            pre[ix][iy]++;
        }
        build();

        // legal函数
        auto legal = [](vector<int>& p1, vector<int>& p2) {
            return p1[1] >= p2[1];
        };

        // 按points[i][0]排序
        ranges::sort(points, [](vector<int>& p1, vector<int>& p2) {
           return p1[0] < p2[0];
        });

        // 遍历获取所有点判断是否可以
        int ans = 0;
        size_t n = points.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (legal(points[i], points[j])) {
                    int a = lower_bound(x_list.begin(), x_list.end(), points[i][0]) - x_list.begin();
                    int b = lower_bound(y_list.begin(), y_list.end(), points[j][1]) - y_list.begin();
                    int c = lower_bound(x_list.begin(), x_list.end(), points[j][0]) - x_list.begin();
                    int d = lower_bound(y_list.begin(), y_list.end(), points[i][1]) - y_list.begin();
                    if (pre_sum(a, b, c, d) == 2) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }

private:
    void build() {
        size_t n = pre.size(), m = pre[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = get(pre, i - 1, j) + get(pre, i, j - 1) - get(pre, i - 1, j - 1);
            }
        }
    }

    int get(vector<vector<int>>& arr, int i, int j) {
        if (i < 0 || j < 0) return 0;
        return arr[i][j];
    }

    int pre_sum(int a, int b, int c, int d) {
        return pre[c][d] - pre[c][b - 1] - pre[a - 1][d] + pre[a - 1][b - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    Solution().numberOfPairs(points);
}