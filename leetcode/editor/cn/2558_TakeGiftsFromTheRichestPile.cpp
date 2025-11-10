// 2025-10-30 10:42:22
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


//You are given an integer array gifts denoting the number of gifts in various 
//piles. Every second, you do the following: 
//
// 
// Choose the pile with the maximum number of gifts. 
// If there is more than one pile with the maximum number of gifts, choose any. 
//
// Reduce the number of gifts in the pile to the floor of the square root of 
//the original number of gifts in the pile. 
// 
//
// Return the number of gifts remaining after k seconds. 
//
// 
// Example 1: 
//
// 
//Input: gifts = [25,64,9,4,100], k = 4
//Output: 29
//Explanation: 
//The gifts are taken in the following way:
//- In the first second, the last pile is chosen and 10 gifts are left behind.
//- Then the second pile is chosen and 8 gifts are left behind.
//- After that the first pile is chosen and 5 gifts are left behind.
//- Finally, the last pile is chosen again and 3 gifts are left behind.
//The final remaining gifts are [5,8,9,4,3], so the total number of gifts 
//remaining is 29.
// 
//
// Example 2: 
//
// 
//Input: gifts = [1,1,1,1], k = 4
//Output: 4
//Explanation: 
//In this case, regardless which pile you choose, you have to leave behind 1 
//gift in each pile. 
//That is, you can't take any pile with you. 
//So, the total gifts remaining are 4.
// 
//
// 
// Constraints: 
//
// 
// 1 <= gifts.length <= 10³ 
// 1 <= gifts[i] <= 10⁹ 
// 1 <= k <= 10³ 
// 
//
// Related Topics 数组 模拟 堆（优先队列） 👍 67 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
typedef long long ll;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        if (gifts.size() == 0) return 0;

        priority_queue<int, vector<int>, less<int>> pq;

        for (const auto& elem : gifts) pq.push(elem);

        while (k--) {
            ll cur = pq.top(); pq.pop();
            pq.push(floor(sqrt(cur)));
        }

        ll ans = 0;
        while (!pq.empty()) {
            ans += pq.top(); pq.pop();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
