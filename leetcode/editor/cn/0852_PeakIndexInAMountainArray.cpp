// 2025-09-11 16:23:12
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//You are given an integer mountain array arr of length n where the values 
//increase to a peak element and then decrease. 
//
// Return the index of the peak element. 
//
// Your task is to solve it in O(log(n)) time complexity. 
//
// 
// Example 1: 
//
// 
// Input: arr = [0,1,0] 
// 
//
// Output: 1 
//
// Example 2: 
//
// 
// Input: arr = [0,2,1,0] 
// 
//
// Output: 1 
//
// Example 3: 
//
// 
// Input: arr = [0,10,5,2] 
// 
//
// Output: 1 
//
// 
// Constraints: 
//
// 
// 3 <= arr.length <= 10⁵ 
// 0 <= arr[i] <= 10⁶ 
// arr is guaranteed to be a mountain array. 
// 
//
// Related Topics 数组 二分查找 👍 458 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, m;
        int n = arr.size();
        if (n == 1) return 0;

        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        while (l <= r) {
            m = l + (r - l) / 2;
            int lv = get(arr, m - 1), rv = get(arr, m + 1);
            if (lv < arr[m] && arr[m] > rv) {
                return m;
            } else if (lv < arr[m] && arr[m] < rv) {
                l = m + 1;
            } else if (lv > arr[m] && arr[m] > rv){
                r = m - 1;
            }
        }
        return 0;
    }

    int get(vector<int>& arr, int pos) {
        if (pos < 0 || pos >= arr.size()) return INT_MIN;
        return arr[pos];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
