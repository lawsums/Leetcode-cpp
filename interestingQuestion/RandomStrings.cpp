// 2025/9/27
#include <DisplayHelper.h>
#include <bits/stdc++.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
 #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;

class Solution {
};

int main() {
    auto s1 = RandomHelper::random_lowercase_string(8);
    auto s2 = RandomHelper::random_lowercase_string(8);
    print_fmt("s1: {0}\ns2: {1}", s1, s2);
}