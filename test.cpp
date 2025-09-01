#include "DisplayHelper.h"
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <bitset>

using namespace std;

void test_basic() {
    int a = 42;
    double b = 3.14;
    string c = "hello";
    vector<int> d = {1, 2, 3};

    // 默认空格分隔
    display::print(a, b, c, d);
    // 输出: 42 3.14 "hello" [1, 2, 3]

    // 逗号分隔
    display::print_delim(", ", a, b, c, d);
    // 输出: 42, 3.14, "hello", [1, 2, 3]

    // 换行分隔
    display::print_delim("\n", a, b, c, d);
    // 输出:
    // 42
    // 3.14
    // "hello"
    // [1, 2, 3]
}

void test_named() {
    int x = 10;
    double y = 20.5;
    string name = "test";

    // 命名显示
    display::print_named({"x", "y", "name"}, x, y, name);
    // 输出: x = 10; y = 20.5; name = "test";
}

void test_complex() {
    map<string, int> ages = {{"Alice", 25}, {"Bob", 30}};
    set<string> names = {"Charlie", "David"};
    tuple<int, string, double> person = {1, "John", 75.5};
    bitset<8> bits(0b10101010);

    display::print("Ages:", ages);
    display::print("Names:", names);
    display::print("Person:", person);
    display::print("Bits:", bits);

    display::separator();  // 使用默认参数

    // 格式化显示
    display::print_fmt("Result: {0} + {1} = {2}", 2, 3, 5);
    // 输出: Result: 2 + 3 = 5
}

void test_nested() {
    // 嵌套数据结构
//    vector<map<string, vector<int>>> complex_data = {
//            {{"scores", {90, 85, 95}}, {"ages", {20, 21}}},
//            {{"prices", {100, 200}}, {"quantities", {5, 10}}}
//    };

    vector<vector<int>> vec{{1, 2 ,3 ,4 ,5}, {1, 2 ,3 ,4 ,5}, {1, 2 ,3 ,4 ,5}, {1, 2 ,3 ,4 ,5}, {1, 2 ,3 ,4 ,5}};
//    display::print("Complex data:", complex_data);
    display::print("Complex data:", vec);
}

int main() {
    test_basic();
    display::separator();

    test_named();
    display::separator();

    test_complex();
    display::separator();

    test_nested();

    return 0;
}