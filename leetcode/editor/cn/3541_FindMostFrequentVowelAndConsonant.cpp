// 2025-09-13 00:07:58
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//You are given a string s consisting of lowercase English letters ('a' to 'z').
// 
//
// Your task is to: 
//
// 
// Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum 
//frequency. 
// Find the consonant (all other letters excluding vowels) with the maximum 
//frequency. 
// 
//
// Return the sum of the two frequencies. 
//
// Note: If multiple vowels or consonants have the same maximum frequency, you 
//may choose any one of them. If there are no vowels or no consonants in the 
//string, consider their frequency as 0. The 
//frequency of a letter 
//x is the number of times it occurs in the string. 
// 
// Example 1: 
//
// 
// Input: s = "successes" 
// 
//
// Output: 6 
//
// Explanation: 
//
// 
// The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency 
//is 2. 
// The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum 
//frequency is 4. 
// The output is 2 + 4 = 6. 
// 
//
// Example 2: 
//
// 
// Input: s = "aeiaeia" 
// 
//
// Output: 3 
//
// Explanation: 
//
// 
// The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). 
//The maximum frequency is 3. 
// There are no consonants in s. Hence, maximum consonant frequency = 0. 
// The output is 3 + 0 = 3. 
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 100 
// s consists of lowercase English letters only. 
// 
//
// Related Topics 哈希表 字符串 计数 👍 6 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnts(26, 0);
        for (const auto& c : s) {
            cnts[c - 'a']++;
        }

        int vowel_cnts = 0, consonant_cnts = 0;
        int x1 = 'a' - 'a', x2 = 'e' - 'a', x3 = 'i' - 'a', x4 = 'o' - 'a', x5 = 'u' - 'a';

        for (int i = 0; i < 26; i++) {
            if (i == x1 || i == x2 || i == x3 || i == x4 || i == x5) { vowel_cnts = max(vowel_cnts, cnts[i]);}
            else { consonant_cnts = max(consonant_cnts, cnts[i]); }
        }
        return vowel_cnts + consonant_cnts;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
