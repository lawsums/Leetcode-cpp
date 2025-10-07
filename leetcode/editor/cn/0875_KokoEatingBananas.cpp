// 2025-09-11 19:42:44
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Koko loves to eat bananas. There are n piles of bananas, the iᵗʰ pile has 
//piles[i] bananas. The guards have gone and will come back in h hours. 
//
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she 
//chooses some pile of bananas and eats k bananas from that pile. If the pile has less 
//than k bananas, she eats all of them instead and will not eat any more bananas 
//during this hour. 
//
// Koko likes to eat slowly but still wants to finish eating all the bananas 
//before the guards return. 
//
// Return the minimum integer k such that she can eat all the bananas within h 
//hours. 
//
// 
// Example 1: 
//
// 
//Input: piles = [3,6,7,11], h = 8
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: piles = [30,11,23,4,20], h = 5
//Output: 30
// 
//
// Example 3: 
//
// 
//Input: piles = [30,11,23,4,20], h = 6
//Output: 23
// 
//
// 
// Constraints: 
//
// 
// 1 <= piles.length <= 10⁴ 
// piles.length <= h <= 10⁹ 
// 1 <= piles[i] <= 10⁹ 
// 
//
// Related Topics 数组 二分查找 👍 711 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(piles, h, m)) {
                r = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }

        return res;
    }

    bool check(vector<int>& piles, int h, int k) {
        long long ans = 0;
        for (const auto& pile : piles) {
            ans += (pile + k - 1) / k;
        }

        return ans <= h;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
