#ifndef DISPLAYHELPER_H
#define DISPLAYHELPER_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <bitset>

class DisplayHelper {
public:
    // 基础版本：适用于任何可迭代容器
    template <typename Iterable>
    static void display(const Iterable& iterable, 
                        const std::string& name = "",
                        const std::string& delimiter = " ");

    // 针对C风格数组的特化
    template <typename T, size_t N>
    static void display(const T (&array)[N], 
                        const std::string& name = "",
                        const std::string& delimiter = " ");

    // 针对二维C风格数组的特化
    template <typename T, size_t Rows, size_t Cols>
    static void display(const T (&matrix)[Rows][Cols], 
                        const std::string& name = "");

    // 针对std::pair的显示
    template <typename T1, typename T2>
    static void display(const std::pair<T1, T2>& pair, 
                        const std::string& name = "");

    // 针对map的显示（键值对格式）
    template <typename Key, typename Value>
    static void display_map(const std::map<Key, Value>& map, 
                            const std::string& name = "");

    // 针对set的显示
    template <typename T>
    static void display_set(const std::set<T>& set, 
                            const std::string& name = "");

    // 显示带索引的序列
    template <typename Iterable>
    static void display_with_index(const Iterable& iterable, 
                                   const std::string& name = "");

    // 显示bitset
    template <size_t N>
    static void display(const std::bitset<N>& bits, 
                        const std::string& name = "");

    // 显示C风格字符串（内联实现）
    static void display(const char* str, const std::string& name = "") {
        if (!name.empty()) {
            std::cout << name << ": ";
        }
        std::cout << "\"" << str << "\"\n";
    }

    // 分隔线（内联实现）
    static void separator(int length = 40, char ch = '-') {
        std::cout << std::string(length, ch) << "\n";
    }
};

// 模板实现必须在头文件中
#include "DisplayHelper.tpp"

#endif // DISPLAYHELPER_H