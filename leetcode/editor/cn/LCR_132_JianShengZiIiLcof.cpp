// 2025-09-14 10:53:33
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//English description is not available for the problem. Please switch to 
//Chinese.
// Related Topics 数学 动态规划 👍 272 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#define MOD 1'000'000'007
typedef unsigned long long ull;
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) return bamboo_len - 1;

        if (bamboo_len % 3 == 1) {
            return (4 * quick_pow(3, (bamboo_len - 4) / 3, MOD)) % MOD;
        } else if (bamboo_len % 3 == 2) {
            return (2 * quick_pow(3, (bamboo_len - 2) / 3, MOD)) % MOD;
        } else return quick_pow(3, bamboo_len / 3, MOD);
    }

    ull quick_pow(ull a, int b, int mod) {
        if (a == 0) return 0;

        ull ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
