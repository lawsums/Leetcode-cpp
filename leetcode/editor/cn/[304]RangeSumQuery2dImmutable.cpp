// 2025-08-27 12:20:08
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//Given a 2D matrix matrix, handle multiple queries of the following type: 
//
// 
// Calculate the sum of the elements of matrix inside the rectangle defined by 
//its upper left corner (row1, col1) and lower right corner (row2, col2). 
// 
//
// Implement the NumMatrix class: 
//
// 
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix 
//matrix. 
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the 
//elements of matrix inside the rectangle defined by its upper left corner (row1, 
//col1) and lower right corner (row2, col2). 
// 
//
// You must design an algorithm where sumRegion works on O(1) time complexity. 
//
// 
// Example 1: 
// 
// 
//Input
//["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
//[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 
//3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
//Output
//[null, 8, 11, 12]
// 
//
//Explanation
//NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 
//0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
//numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
//numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
//
//numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
//
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// -10⁴ <= matrix[i][j] <= 10⁴ 
// 0 <= row1 <= row2 < m 
// 0 <= col1 <= col2 < n 
// At most 10⁴ calls will be made to sumRegion. 
// 
//
// Related Topics 设计 数组 矩阵 前缀和 👍 615 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
private:
    vector<vector<int>> pre;

    int get(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0) return 0;
        return grid[i][j];
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        pre.assign(n, vector<int>(m, 0));

        // 构造前缀和
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 用get避免出界
                pre[i][j] = matrix[i][j] + get(pre, i - 1, j)  + get(pre, i, j - 1) - get(pre, i - 1, j - 1);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get(pre, row2, col2) - get(pre, row1 - 1, col2) - get(pre, row2, col1 - 1) + get(pre, row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)
