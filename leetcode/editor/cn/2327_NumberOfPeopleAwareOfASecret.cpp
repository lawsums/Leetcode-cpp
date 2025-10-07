// 2025-09-09 00:21:12
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//On day 1, one person discovers a secret. 
//
// You are given an integer delay, which means that each person will share the 
//secret with a new person every day, starting from delay days after discovering 
//the secret. You are also given an integer forget, which means that each person 
//will forget the secret forget days after discovering it. A person cannot share the 
//secret on the same day they forgot it, or on any day afterwards. 
//
// Given an integer n, return the number of people who know the secret at the 
//end of day n. Since the answer may be very large, return it modulo 10⁹ + 7. 
//
// 
// Example 1: 
//
// 
//Input: n = 6, delay = 2, forget = 4
//Output: 5
//Explanation:
//Day 1: Suppose the first person is named A. (1 person)
//Day 2: A is the only person who knows the secret. (1 person)
//Day 3: A shares the secret with a new person, B. (2 people)
//Day 4: A shares the secret with a new person, C. (3 people)
//Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 
//people)
//Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
// 
//
// Example 2: 
//
// 
//Input: n = 4, delay = 1, forget = 3
//Output: 6
//Explanation:
//Day 1: The first person is named A. (1 person)
//Day 2: A shares the secret with B. (2 people)
//Day 3: A and B share the secret with 2 new people, C and D. (4 people)
//Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (
//6 people)
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 1000 
// 1 <= delay < forget <= n 
// 
//
// Related Topics 队列 动态规划 模拟 👍 96 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#define MOD 1'000'000'007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> changes(n + 1, 0); // 表示每个时间节点知道秘密的人数变化量
        changes[1] = 1;
        int windows = 0; // 现在的窗口
        int cur = 1; // changes[0]
        for (int i = 2 /* i从2开始 */, r = 1, l = 1; i < changes.size(); i++) {
            if (r <= i - delay) {
                windows = (windows + changes[i - delay]) % MOD;
                r++;
            }
            if (l <= i - forget) {
                windows = (windows - changes[i - forget] + MOD) % MOD; // 注意C++的取余涉及负数必须+MOD
                cur = (cur - changes[i - forget] + MOD) % MOD; // 同理
                l++;
            }
            changes[i] = windows;
            cur = (cur + changes[i]) % MOD;
        }

        return cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
