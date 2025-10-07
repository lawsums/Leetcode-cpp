// 2025-08-30 10:05:04
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

//English description is not available for the problem. Please switch to
//Chinese.
//
// Related Topics 数组 数学 字符串 排序 👍 52 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
#include <ranges>
class Solution {
private:
    int minus(string t1, string t2) {
        int ans = (stoi(t1.substr(0, 2)) - stoi(t2.substr(0, 2))) * 60
                  +stoi(t1.substr(3)) - stoi(t2.substr(3));
        return t1 < t2 ? ans + 24 * 60 : ans;
    }
public:
    int findMinDifference(vector<string> &timePoints) {
        int ans = INT_MAX, n = timePoints.size();
        if (n > 24 * 60) return 0;
        ranges::sort(timePoints);
        for (int i = 0; i < n; i++) {
            ans = min(ans,
                      min(minus(timePoints[i], timePoints[(i + 1) % n]),
                          minus(timePoints[(i + 1) % n], timePoints[i])));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<string> timePoints = {"23:59", "00:00"};
    cout << Solution().findMinDifference(timePoints);
}