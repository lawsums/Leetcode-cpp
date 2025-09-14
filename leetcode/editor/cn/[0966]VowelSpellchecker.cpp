// 2025-09-14 08:26:40
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <ranges>

using namespace std;

//Given a wordlist, we want to implement a spellchecker that converts a query 
//word into a correct word. 
//
// For a given query word, the spell checker handles two categories of spelling 
//mistakes: 
//
// 
// Capitalization: If the query matches a word in the wordlist (case-
//insensitive), then the query word is returned with the same case as the case in the 
//wordlist. 
// 
//
// 
// Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow" 
// Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow" 
// Example: wordlist = ["yellow"], query = "yellow": correct = "yellow" 
// 
// 
// Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the 
//query word with any vowel individually, it matches a word in the wordlist (case-
//insensitive), then the query word is returned with the same case as the match 
//in the wordlist.
// 
// Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw" 
// Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match) 
// Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match) 
// 
// 
//
//
// In addition, the spell checker operates under the following precedence rules:
// 
//
// 
// When the query exactly matches a word in the wordlist (case-sensitive), you 
//should return the same word back. 
// When the query matches a word up to capitlization, you should return the 
//first such match in the wordlist. 
// When the query matches a word up to vowel errors, you should return the 
//first such match in the wordlist. 
// If the query has no matches in the wordlist, you should return the empty 
//string. 
// 
//
// Given some queries, return a list of words answer, where answer[i] is the 
//correct word for query = queries[i]. 
//
// 
// Example 1: 
// Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite",
//"KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
//Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
// 
// Example 2: 
// Input: wordlist = ["yellow"], queries = ["YellOw"]
//Output: ["yellow"]
// 
// 
// Constraints: 
//
// 
// 1 <= wordlist.length, queries.length <= 5000 
// 1 <= wordlist[i].length, queries[i].length <= 7 
// wordlist[i] and queries[i] consist only of only English letters. 
// 
//
// Related Topics 数组 哈希表 字符串 👍 50 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    string vowels = "aeiou";
    unordered_map<string, string> mp;

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // 解决通配项问题
        for (auto& word : wordlist) {
            push(word, mp);
        }

        vector<string> ans;
        for (const auto& query : queries) {
            if (!mp.count(query)) ans.push_back("");
            else ans.push_back(mp[query]);
        }

        return ans;
    }

    bool check(unsigned char c) {
        return vowels.find(c) != string::npos;
    }

    void push(string& word, unordered_map<string, string>& mp) {
        mp[word] = word; // 确保自己对应的是自己
        string s(word.begin(), word.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // 获取所有大小写word
        string path;
        dfs(0, path, s, word);
    }

    void dfs(int step, string& path, string& s, string& word) {
        if (step == s.size()) {
            if (!mp.count(path)) { mp[path] = word; }
            return;
        }

        if (!check(s[step])) {
            path.push_back(s[step]);
            dfs(step + 1, path, s, word);
            path.pop_back();

            path.push_back(toupper(s[step]));
            dfs(step + 1, path, s, word);
            path.pop_back();
        } else { // 元音
            for (int i = 0; i < 5; i++) {
                char vowel = vowels[i];

                path.push_back(vowel);
                dfs(step + 1, path, s, word);
                path.pop_back();

                path.push_back(toupper(vowel));
                dfs(step + 1, path, s, word);
                path.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    auto ans = Solution().spellchecker(wordlist, queries);
    display::print(ans);
}