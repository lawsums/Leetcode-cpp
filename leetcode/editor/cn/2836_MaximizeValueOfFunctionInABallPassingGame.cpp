// 2025-10-06 19:39:02
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given an integer array receiver of length n and an integer k. n 
//players are playing a ball-passing game. 
//
// You choose the starting player, i. The game proceeds as follows: player i 
//passes the ball to player receiver[i], who then passes it to receiver[receiver[i]],
// and so on, for k passes in total. The game's score is the sum of the indices 
//of the players who touched the ball, including repetitions, i.e. i + receiver[i] +
// receiver[receiver[i]] + ... + receiver⁽ᵏ⁾[i]. 
//
// Return the maximum possible score. 
//
// Notes: 
//
// 
// receiver may contain duplicates. 
// receiver[i] may be equal to i. 
// 
//
// 
// Example 1: 
//
// 
// Input: receiver = [2,0,1], k = 4 
// 
//
// Output: 6 
//
// Explanation: 
//
// Starting with player i = 2 the initial score is 2: 
//
// 
// 
// 
// Pass 
// Sender Index 
// Receiver Index 
// Score 
// 
// 
// 1 
// 2 
// 1 
// 3 
// 
// 
// 2 
// 1 
// 0 
// 3 
// 
// 
// 3 
// 0 
// 2 
// 5 
// 
// 
// 4 
// 2 
// 1 
// 6 
// 
// 
// 
//
// Example 2: 
//
// 
// Input: receiver = [1,1,1,2,3], k = 3 
// 
//
// Output: 10 
//
// Explanation: 
//
// Starting with player i = 4 the initial score is 4: 
//
// 
// 
// 
// Pass 
// Sender Index 
// Receiver Index 
// Score 
// 
// 
// 1 
// 4 
// 3 
// 7 
// 
// 
// 2 
// 3 
// 2 
// 9 
// 
// 
// 3 
// 2 
// 1 
// 10 
// 
// 
// 
//
// 
// Constraints: 
//
// 
// 1 <= receiver.length == n <= 10⁵ 
// 0 <= receiver[i] <= n - 1 
// 1 <= k <= 10¹⁰ 
// 
//
// Related Topics 位运算 数组 动态规划 👍 36 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        // 构建成环的数组

        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
