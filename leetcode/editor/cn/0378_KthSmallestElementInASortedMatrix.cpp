// 2025-09-12 23:43:55
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

//Given an n x n matrix where each of the rows and columns is sorted in 
//ascending order, return the kᵗʰ smallest element in the matrix. 
//
// Note that it is the kᵗʰ smallest element in the sorted order, not the kᵗʰ 
//distinct element. 
//
// You must find a solution with a memory complexity better than O(n²). 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
//Output: 13
//Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and 
//the 8ᵗʰ smallest number is 13
// 
//
// Example 2: 
//
// 
//Input: matrix = [[-5]], k = 1
//Output: -5
// 
//
// 
// Constraints: 
//
// 
// n == matrix.length == matrix[i].length 
// 1 <= n <= 300 
// -10⁹ <= matrix[i][j] <= 10⁹ 
// All the rows and columns of matrix are guaranteed to be sorted in non-
//decreasing order. 
// 1 <= k <= n² 
// 
//
// 
// Follow up: 
//
// 
// Could you solve the problem with a constant memory (i.e., O(1) memory 
//complexity)? 
// Could you solve the problem in O(n) time complexity? The solution may be too 
//advanced for an interview but you may find reading this paper fun. 
// 
//
// Related Topics 数组 二分查找 矩阵 排序 堆（优先队列） 👍 1140 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int ans = 0;
        while (k--) {
            auto [val, i, j] = pq.top(); pq.pop();
            ans = val;
            if (j + 1 < matrix[i].size()) {
                pq.push({matrix[i][j + 1], i, j + 1});
            }

        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
