// 2025-10-09 23:36:38
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//Given a string s and an integer k, return true if you can use all the 
//characters in s to construct non-empty k palindrome strings or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: s = "annabelle", k = 2
//Output: true
//Explanation: You can construct two palindromes using all characters in s.
//Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + 
//"b"
// 
//
// Example 2: 
//
// 
//Input: s = "leetcode", k = 3
//Output: false
//Explanation: It is impossible to construct 3 palindromes using all the 
//characters of s.
// 
//
// Example 3: 
//
// 
//Input: s = "true", k = 4
//Output: true
//Explanation: The only possible solution is to put each character in a 
//separate string.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s consists of lowercase English letters. 
// 1 <= k <= 10⁵ 
// 
//
// Related Topics 贪心 哈希表 字符串 计数 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int k;

public:
//    bool dfs(int step, int where, string& s) {
//        for (int i = 0; i < step; i++) cout << '\t';
//        print_fmt("step: {0}, where: {1}", step, where);
//        if (step > k || where > s.size()) return false;
//        if (step == k && where == s.size()) return true;
//
////        if (step == 2) {
////            cout << "I'm 2" << endl;
////        }
//
//        for (int i = 1; i <= s.size(); i++) {
//            // int res = k - step - 1; res /* 还需要最起码多少个字符 */ + where + i <= s.size()
//            if (where + i < s.size() && check(where, where + i - 1, s) && dfs(step + 1 , where + i, s)) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool check(int l, int r, string& s) {
//        while (l < r) {
//            if (s[l++] != s[r--]) {
//                return false;
//            }
//        }
//        return true;
//    }

    bool canConstruct(string s, int k) {
        
//        this->k = k;
//        if (k > s.size()) return false;
//        if (k == s.size()) return true;
//
//        return dfs(0, 0, s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
//    string s = "annabelle";
//    int k = 2;
//    print_fmt("s.size() = {0}, k = {1}", s.size(), k);
//    cout << Solution().canConstruct(s, k) << endl;
}