// 2025-08-31 16:57:06
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//We are given an array asteroids of integers representing asteroids in a row. 
//The indices of the asteriod in the array represent their relative position in 
//space. 
//
// For each asteroid, the absolute value represents its size, and the sign 
//represents its direction (positive meaning right, negative meaning left). Each 
//asteroid moves at the same speed. 
//
// Find out the state of the asteroids after all collisions. If two asteroids 
//meet, the smaller one will explode. If both are the same size, both will explode. 
//Two asteroids moving in the same direction will never meet. 
//
// 
// Example 1: 
//
// 
//Input: asteroids = [5,10,-5]
//Output: [5,10]
//Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never 
//collide.
// 
//
// Example 2: 
//
// 
//Input: asteroids = [8,-8]
//Output: []
//Explanation: The 8 and -8 collide exploding each other.
// 
//
// Example 3: 
//
// 
//Input: asteroids = [10,2,-5]
//Output: [10]
//Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide 
//resulting in 10.
// 
//
// 
// Constraints: 
//
// 
// 2 <= asteroids.length <= 10⁴ 
// -1000 <= asteroids[i] <= 1000 
// asteroids[i] != 0 
// 
//
// Related Topics 栈 数组 模拟 👍 556 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        if (n <= 1) return asteroids;

        vector<int> ans;
        while (asteroids.size() > 1) {
            n = asteroids.size();
            int left = asteroids[n - 2], right = asteroids[n - 1];
            asteroids.pop_back(); // 销毁两个行星
            asteroids.pop_back();
            if (left > 0 && right < 0) {
                if (left + right > 0) {
                    asteroids.push_back(left); // 销毁右边的负数行星
                } else if (left + right < 0) {
                    asteroids.push_back(right);
                }
            } else {
                asteroids.push_back(left); // 移动一颗行星到ans中
                ans.push_back(right);
            }
        }
        if (!asteroids.empty()) {
            ans.push_back(asteroids[0]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums = {5,10,-5};
    auto ans = Solution().asteroidCollision(nums);
    for (const auto& elem : ans) cout << elem << ", ";
}