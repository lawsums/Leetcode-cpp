// 2025-08-27 12:36:14
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 数组 前缀和 👍 79 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);
        partial_sum(nums.begin(), nums.end(), pre.begin() + 1);
        partial_sum(nums.rbegin(), nums.rend(), suf.begin() + 1);
        suf.pop_back();
        reverse(suf.begin(), suf.end());

        for (int i = 0; i < n; i++)  {
            if (pre[i] == suf[i]) {
                return i;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//int main() {
//    vector<int> nums = {1,7,3,6,5,6};
//    Solution().pivotIndex(nums);
//}