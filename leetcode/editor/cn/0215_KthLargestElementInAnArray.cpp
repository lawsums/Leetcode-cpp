// 2025-09-10 16:44:15
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given an integer array nums and an integer k, return the kᵗʰ largest element 
//in the array. 
//
// Note that it is the kᵗʰ largest element in the sorted order, not the kᵗʰ 
//distinct element. 
//
// Can you solve it without sorting? 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// 
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 2811 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MergeSort(nums);
        return nums.size() >= k ? nums[k - 1] : -1;
    }

    void MergeSort(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
    }

    void MergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int m = (l + r) / 2;
        MergeSort(nums, l, m);
        MergeSort(nums, m + 1, r);
        Merge(nums, l, m, r);
    }

    void Merge(vector<int>& nums, int start, int m, int end) {
        int l = start, r = m + 1;
        vector<int> tmp;
        while (l <= m && r <= end) {
            if (nums[l] >= nums[r]) tmp.push_back(nums[l++]);
            else tmp.push_back(nums[r++]);
        }
        while (l <= m) tmp.push_back(nums[l++]);
        while (r <= end) tmp.push_back(nums[r++]);

        // 放回原数组
        for (int i = 0; i < tmp.size(); i++) {
            nums[start + i] = tmp[i];
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
