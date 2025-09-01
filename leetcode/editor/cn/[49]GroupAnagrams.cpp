// 2025-08-30 09:32:03
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

//Given an array of strings strs, group the anagrams together. You can return 
//the answer in any order. 
//
// 
// Example 1: 
//
// 
// Input: strs = ["eat","tea","tan","ate","nat","bat"] 
// 
//
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]] 
//
// Explanation: 
//
// 
// There is no string in strs that can be rearranged to form "bat". 
// The strings "nat" and "tan" are anagrams as they can be rearranged to form 
//each other. 
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged 
//to form each other. 
// 
//
// Example 2: 
//
// 
// Input: strs = [""] 
// 
//
// Output: [[""]] 
//
// Example 3: 
//
// 
// Input: strs = ["a"] 
// 
//
// Output: [["a"]] 
//
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lowercase English letters. 
// 
//
// Related Topics 数组 哈希表 字符串 排序 👍 2381 👎 0


// #include "../../../ListOperations.h"


#include <unordered_map>

//leetcode submit region begin(Prohibit modification and deletion)
#include <ranges>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;
         for (string &s : strs) {
             string sorted_s = s;
             ranges::sort(sorted_s);
             mp[sorted_s].push_back(s);
         }

         vector<vector<string>> ans;
         ans.reserve(mp.size());
         for (const auto& [_, value] : mp) {
             ans.push_back(value);
         }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto ans = Solution().groupAnagrams(strs);
    for (const auto& row : ans) {
        for (const auto& elem : row) {
            cout << elem << endl;
        }
    }
}