// 2025-09-27 01:14:58
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>

using namespace std;
using namespace display;


//A sequence x1, x2, ..., xn is Fibonacci-like if: 
//
// 
// n >= 3 
// xi + xi+1 == xi+2 for all i + 2 <= n 
// 
//
// Given a strictly increasing array arr of positive integers forming a 
//sequence, return the length of the longest Fibonacci-like subsequence of arr. If one 
//does not exist, return 0. 
//
// A subsequence is derived from another sequence arr by deleting any number of 
//elements (including none) from arr, without changing the order of the remaining 
//elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8]. 
//
// 
// Example 1: 
//
// 
//Input: arr = [1,2,3,4,5,6,7,8]
//Output: 5
//Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8]. 
//
// Example 2: 
//
// 
//Input: arr = [1,3,7,11,12,14,18]
//Output: 3
//Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,
//14] or [7,11,18]. 
//
// 
// Constraints: 
//
// 
// 3 <= arr.length <= 1000 
// 1 <= arr[i] < arr[i + 1] <= 10⁹ 
// 
//
// Related Topics 数组 哈希表 动态规划 👍 418 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if (arr.size() <= 3) return 0;

        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        int ans = 2;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j], cnt = 2;
                while (mp.count(a + b)) {
                    int tmp = a;
                    a = b;
                    b = tmp + b;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans == 2 ? 0 : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
