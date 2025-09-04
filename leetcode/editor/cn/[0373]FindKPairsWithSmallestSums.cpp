// 2025-09-04 17:00:29
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given two integer arrays nums1 and nums2 sorted in non-decreasing 
//order and an integer k. 
//
// Define a pair (u, v) which consists of one element from the first array and 
//one element from the second array. 
//
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums. 
//
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//Output: [[1,2],[1,4],[1,6]]
//Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,
//6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// 
//
// Example 2: 
//
// 
//Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//Output: [[1,1],[1,1]]
//Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,
//2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums1.length, nums2.length <= 10⁵ 
// -10⁹ <= nums1[i], nums2[i] <= 10⁹ 
// nums1 and nums2 both are sorted in non-decreasing order. 
// 1 <= k <= 10⁴ 
// k <= nums1.length * nums2.length 
// 
//
// Related Topics 数组 堆（优先队列） 👍 678 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <queue>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return (a[0] + a[1]) > (b[0] + b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>
                q(cmp);

        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                q.push({nums1[i], nums2[j]});
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < min(n*m, k); i++) {
            ans.push_back(q.top());
            q.pop();
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
