// 2025-11-02 18:01:14
#include <bits/stdc++.h>
#include <DisplayHelper.h>
#include <Heap.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given two integer arrays, nums1 and nums2, both of length n, along 
//with a positive integer k. 
//
// For each index i from 0 to n - 1, perform the following: 
//
// 
// Find all indices j where nums1[j] is less than nums1[i]. 
// Choose at most k values of nums2[j] at these indices to maximize the total 
//sum. 
// 
//
// Return an array answer of size n, where answer[i] represents the result for 
//the corresponding index i. 
//
// 
// Example 1: 
//
// 
// Input: nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2 
// 
//
// Output: [80,30,0,80,50] 
//
// Explanation: 
//
// 
// For i = 0: Select the 2 largest values from nums2 at indices [1, 2, 4] where 
//nums1[j] < nums1[0], resulting in 50 + 30 = 80. 
// For i = 1: Select the 2 largest values from nums2 at index [2] where nums1[j]
// < nums1[1], resulting in 30. 
// For i = 2: No indices satisfy nums1[j] < nums1[2], resulting in 0. 
// For i = 3: Select the 2 largest values from nums2 at indices [0, 1, 2, 4] 
//where nums1[j] < nums1[3], resulting in 50 + 30 = 80. 
// For i = 4: Select the 2 largest values from nums2 at indices [1, 2] where 
//nums1[j] < nums1[4], resulting in 30 + 20 = 50. 
// 
//
// Example 2: 
//
// 
// Input: nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1 
// 
//
// Output: [0,0,0,0] 
//
// Explanation: 
//
// Since all elements in nums1 are equal, no indices satisfy the condition nums1
//[j] < nums1[i] for any i, resulting in 0 for all positions. 
//
// 
// Constraints: 
//
// 
// n == nums1.length == nums2.length 
// 1 <= n <= 10⁵ 
// 1 <= nums1[i], nums2[i] <= 10⁶ 
// 1 <= k <= n 
// 
//
// Related Topics 数组 排序 堆（优先队列） 👍 16 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [=](int a, int b){
            return nums1[a] < nums1[b];
        });

        print_fmt("indices = {0}", indices);

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums1 = {4,2,1,5,3}, nums2 = {10,20,30,40,50};
    int k = 2;

    Solution().findMaxSum(nums1, nums2, k);
}