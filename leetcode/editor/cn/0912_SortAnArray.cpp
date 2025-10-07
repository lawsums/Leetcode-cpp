// 2025-09-10 20:55:39
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given an array of integers nums, sort the array in ascending order and return 
//it. 
//
// You must solve the problem without using any built-in functions in O(nlog(n))
// time complexity and with the smallest space complexity possible. 
//
// 
// Example 1: 
//
// 
//Input: nums = [5,2,3,1]
//Output: [1,2,3,5]
//Explanation: After sorting the array, the positions of some numbers are not 
//changed (for example, 2 and 3), while the positions of other numbers are changed (
//for example, 1 and 5).
// 
//
// Example 2: 
//
// 
//Input: nums = [5,1,1,2,0,0]
//Output: [0,0,1,1,2,5]
//Explanation: Note that the values of nums are not necessarily unique.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
//
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 1152 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums);
        return nums;
    }

    void MergeSort(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
    }

    void MergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int m = (start + end) / 2;
        MergeSort(nums, start, m);
        MergeSort(nums, m + 1, end);
        Merge(nums, start, m, end);
    }

    void Merge(vector<int>& nums, int start, int m, int end) {
        vector<int> tmp;
        int l = start, r = m + 1;

        // 组织tmp数组
        while (l <= m && r <= end) {
            if (nums[l] <= nums[r]) tmp.push_back(nums[l++]);
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
