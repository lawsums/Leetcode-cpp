// 2025-09-01 16:53:22
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given a rows x cols binary matrix filled with 0's and 1's, find the largest 
//rectangle containing only 1's and return its area. 
//
// 
// Example 1: 
// 
// 
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1",
//"1"],["1","0","0","1","0"]]
//Output: 6
//Explanation: The maximal rectangle is shown in the above picture.
// 
//
// Example 2: 
//
// 
//Input: matrix = [["0"]]
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: matrix = [["1"]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// rows == matrix.length 
// cols == matrix[i].length 
// 1 <= row, cols <= 200 
// matrix[i][j] is '0' or '1'. 
// 
//
// Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 1756 👎 0


// #include "../../../ListOperations.h"
// #include "../../../StringOperations.h"
#include "../../../DisplayHelper.h"

#include <stack>
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int n, m;
    vector<vector<int>> grid;

    void build(vector<vector<char>>& matrix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = matrix[i][j] - '0';
            }
        }
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        this->n = matrix.size(), this->m = matrix[0].size();
        grid.assign(n, vector<int>(m, 0));
        build(matrix);

        int ans = 0;
        vector<int> row(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) row[j]++;
                else row[j] = 0;
            }
            ans = max(ans, f1(row));
        }
        return ans;
    }

    int f1(vector<int>& matrix) {
        int n = matrix.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && matrix[mono_stack.top()] >= matrix[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * matrix[i]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
