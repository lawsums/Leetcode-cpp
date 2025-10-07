//
// Created by Hello on 2025/9/24.
//

//两个0和1数量相等区间的最大长度
//给出一个长度为n的01串，现在请你找到两个区间使得这两个区间中，1的个数相等，0的个数也相等
//这两个区间可以相交，但是不可以完全重叠，即两个区间的左右端点不可以完全一样现在请你找到两个最长的区间，满足以上要求
//返回区间最大长度
//来自真实大厂笔试，没有在线测试，对数器验证


#include "../include/DisplayHelper.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace display;

class SimpleRandom {
    static std::mt19937 &get_generator() {
        static random_device rd;
        static mt19937 gen(rd());
        return gen;
    }

public:
    static int random_int(int min, int max) {
        uniform_int_distribution<int> dist(min, max);
        return dist(get_generator());
    }
};

class Solution {
private:
public:
    // 找到左右最早的00对和11对，比较他们的距离和
    // 这个解法是对的
    int solver(vector<int>& arr) {
        int leftZero = -1;
        int rightZero = -1;
        int leftOne = -1;
        int rightOne = -1;

        // 找到第一个0和第一个1
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                leftZero = i;
                break;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                leftOne = i;
                break;
            }
        }

        // 找到最后一个0和最后一个1
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                rightZero = i;
                break;
            }
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == 1) {
                rightOne = i;
                break;
            }
        }

        int p1 = rightZero - leftZero;
        int p2 = rightOne - leftOne;
        return max(p1, p2);
    }


    int checker(vector<int> &nums) {
        if (nums.size() <= 1) return 0;
        unordered_map<int, int> mp;// 01数量, 存在

        int ans = 1;
        for (int l = 0; l < nums.size(); l++) {
            int cnt0 = 0, cnt1 = 0;
            for (int r = l; r < nums.size(); r++) {
                if (nums[r] == 0) cnt0++;
                else
                    cnt1++;
                if (r - l >= 1) {// 需要区间长度大于等于2
                    int tmp = cnt0 * nums.size() + cnt1;
                    if (mp.count(tmp)) ans = max(ans, mp[tmp]);
                    else
                        mp[tmp] = r - l + 1;
                }
            }
        }
        return ans;
    }


    void compare() {
        int N = 1000;// 实验次数
        int M = 10;   // 数组长度
        int wrongs = 0;
        for (int i = 0; i < N; i++) {
            int L = SimpleRandom::random_int(M / 2, M);
            vector<int> tmp(L);
            for (int j = 0; j < L; j++) {
                tmp[j] = SimpleRandom::random_int(0, 1);
            }
            if (i > 0 && i % 100 == 0) { print_fmt("It's {0} times", i); }
            int ans_s = solver(tmp), ans_c = checker(tmp);
            if (ans_s != ans_c) {
                print_fmt("[Wrong]: {0} with solver's ans: {1} and checker's ans: {2}", tmp, ans_s, ans_c);
                wrongs++;
            }
        }

        print_fmt("Your solution's presicion is {0}", 1.0 - (1.0 * wrongs / N));
    }
};


int main() {
    Solution().compare();
    //    vector<int> nums = {1, 0, 1, 0, 1, 1};
    //    cout << Solution().solver(nums) << endl;
    //    cout << Solution().checker(nums) << endl;
}