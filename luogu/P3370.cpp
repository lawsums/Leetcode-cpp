//# P3370 【模板】字符串哈希
//
//## 题目描述
//
//                如题，给定 $N$ 个字符串（第 $i$ 个字符串长度为 $M_i$，字符串内包含数字、大小写字母，大小写敏感），请求出 $N$ 个字符串中共有多少个不同的字符串。
//
//
//                        **友情提醒：如果真的想好好练习哈希的话，请自觉。**
//
//        ## 输入格式
//
//                第一行包含一个整数 $N$，为字符串的个数。
//
//                        接下来 $N$ 行每行包含一个字符串，为所提供的字符串。
//
//        ## 输出格式
//
//                输出包含一行，包含一个整数，为不同的字符串个数。
//
//        ## 输入输出样例 #1
//
//        ### 输入 #1
//
//```
//        5
//        abc
//                aaaa
//                        abc
//                                abcc
//        12345
//```
//
//        ### 输出 #1
//
//```
//        4
//```
//
//        ## 说明/提示
//
//        ### 数据范围
//
//        对于 $30\%$ 的数据：$N\leq 10$，$M_i≈6$，$M_{\max}\leq 15$。
//
//                对于 $70\%$ 的数据：$N\leq 1000$，$M_i≈100$，$M_{\max}\leq 150$。
//
//                对于 $100\%$ 的数据：$N\leq 10000$，$M_i≈1000$，$M_{\max}\leq 1500$。
//
//### 样例说明
//
//样例中第一个字符串 $\tt{abc}$ 和第三个字符串 $\tt{abc}$ 是一样的，所以所提供字符串的集合为 $\{\tt{aaaa},\tt{abc},\tt{abcc},\tt{12345}\}$，故共计 $4$ 个不同的字符串。
//
//### 拓展阅读
//
//以下的一些试题从不同层面体现出了字符串哈希算法的正确性分析。
//
//- [P12197 Hash Killer I](https://www.luogu.com.cn/problem/P12197)
//- [P12198 Hash Killer II](https://www.luogu.com.cn/problem/P12198)
//- [P12199 （目前无解）Hash Killer III](https://www.luogu.com.cn/problem/P12199)
//- [P12200 Hash Killer Extra](https://www.luogu.com.cn/problem/P12200)
//- [P12201 Hash Killer Phantasm](https://www.luogu.com.cn/problem/P12201)
//- [P7350 「MCOI-04」Dream and Strings](https://www.luogu.com.cn/problem/P7350)

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

typedef long long ll;

using namespace std;

class Solution{
private:
    ll base = 499;

private:
    int mapping(char c) {
        if (isdigit(c)) {
            return c - '0' + 1;
        } else if ('a' <= c && c <= 'z') {
            return c - 'a' + 11;
        } else if ('A' <= c && c <= 'Z') {
            return c - 'A' + 37;
        }
        // 题目没有要求其他字符
        return -1;
    }

public:
    ll string_hash(const string& s) {
        int n = s.size();
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans * base + mapping(s[i]);
        }
        return ans;
    }

    int cnt(vector<ll>& nums) {
        int ans = 1;
        sort(nums.begin(), nums.end()); // 我没排序!!!!!
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { ans++; }
        }
        return ans;
    }
};

int main() {
    auto sol = Solution();
    // readlines
    int N;
    cin >> N;

    string line;
    vector<string> ss;
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        ss.push_back(line);
    }

    vector<ll> ls(N, 0);
    for (int i = 0; i < N; i++) {
        ls[i] = sol.string_hash(ss[i]);
    }

    cout << sol.cnt(ls) << endl;
}