// 2025-09-26 17:00:33
#include <bits/stdc++.h>
// #include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
// using namespace display;


//There is a forest with an unknown number of rabbits. We asked n rabbits "How 
//many rabbits have the same color as you?" and collected the answers in an 
//integer array answers where answers[i] is the answer of the iᵗʰ rabbit. 
//
// Given the array answers, return the minimum number of rabbits that could be 
//in the forest. 
//
// 
// Example 1: 
//
// 
//Input: answers = [1,1,2]
//Output: 5
//Explanation:
//The two rabbits that answered "1" could both be the same color, say red.
//The rabbit that answered "2" can't be red or the answers would be 
//inconsistent.
//Say the rabbit that answered "2" was blue.
//Then there should be 2 other blue rabbits in the forest that didn't answer 
//into the array.
//The smallest possible number of rabbits in the forest is therefore 5: 3 that 
//answered plus 2 that didn't.
// 
//
// Example 2: 
//
// 
//Input: answers = [10,10,10]
//Output: 11
// 
//
// 
// Constraints: 
//
// 
// 1 <= answers.length <= 1000 
// 0 <= answers[i] < 1000 
// 
//
// Related Topics 贪心 数组 哈希表 数学 👍 324 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (const auto& x : answers) {
            mp[x]++;
        }

        int ans = 0;
        for (const auto& [key, v] : mp) {
            int k = key + 1;
            ans += k * ((v + k - 1) / k);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
