#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull BASE = 499;

class Solution {
private:
    vector<ull> hashed;
    vector<ull> pow_arr;

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};

        int n = s.size();
        int wordLen = words[0].size();
        int wordNum = words.size();
        int allLen = wordLen * wordNum;

        if (n < allLen) return {};

        // 预处理哈希和幂数组
        build(s);

        // 计算words的哈希频率
        unordered_map<ull, int> target;
        for (const auto& word : words) {
            target[hash(word)]++;
        }

        vector<int> ans;

        // 对每个同余分组进行处理
        for (int init = 0; init < wordLen && init + allLen <= n; init++) {
            unordered_map<ull, int> window;
            int debt = wordNum;

            // 初始化窗口
            for (int i = 0; i < wordNum; i++) {
                int start = init + i * wordLen;
                ull h = hash(start, start + wordLen - 1);
                window[h]++;
                if (window[h] <= target[h]) {
                    debt--;
                }
            }

            if (debt == 0) {
                ans.push_back(init);
            }

            // 滑动窗口：每次移动一个单词的距离
            for (int l = init, r = init + allLen; r + wordLen <= n; l += wordLen, r += wordLen) {
                // 移除左边的单词
                ull out_hash = hash(l, l + wordLen - 1);
                window[out_hash]--;
                if (window[out_hash] < target[out_hash]) {
                    debt++;
                }

                // 添加右边的单词
                ull in_hash = hash(r, r + wordLen - 1);
                window[in_hash]++;
                if (window[in_hash] <= target[in_hash]) {
                    debt--;
                }

                if (debt == 0) {
                    ans.push_back(l + wordLen);
                }
            }
        }

        // 排序结果（虽然题目说可以任意顺序，但通常测试用例期望排序）
        sort(ans.begin(), ans.end());
        return ans;
    }

private:
    void build(const string& s) {
        int n = s.size();
        hashed.resize(n);
        pow_arr.resize(n + 1);

        // 初始化幂数组
        pow_arr[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow_arr[i] = pow_arr[i - 1] * BASE; // 使用ull类型自然溢出
        }

        // 初始化哈希数组
        hashed[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            hashed[i] = hashed[i - 1] * BASE + (s[i] - 'a' + 1); // 自然溢出
        }
    }

    // 计算子串 s[l..r] 的哈希值
    ull hash(int l, int r) {
        if (l == 0) return hashed[r];
        return hashed[r] - hashed[l - 1] * pow_arr[r - l + 1];
    }

    // 计算整个字符串的哈希值
    ull hash(const string& str) {
        ull h = 0;
        for (char c : str) {
            h = h * BASE + (c - 'a' + 1);
        }
        return h;
    }
};