// 2025-08-27 11:37:03
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { // 跳过重复的num[i]
                continue;
            }
            int x = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = x + nums[j] + nums[k];
                if (sum == 0) { // 相等的话就要跳过重复解
                    ans.push_back({x, nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution().threeSum(nums);
}