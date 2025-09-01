#ifndef DISPLAYHELPER_TPP
#define DISPLAYHELPER_TPP

#include "DisplayHelper.h"
#include <iostream>
#include <type_traits>

// 基础版本：适用于任何可迭代容器
template <typename Iterable>
void DisplayHelper::display(const Iterable& iterable,
                            const std::string& name,
                            const std::string& delimiter) {
    if (!name.empty()) {
        std::cout << name << ": ";
    }

    for (const auto& element : iterable) {
        std::cout << element << delimiter;
    }
    std::cout << "\n";
}

// 针对C风格数组的特化
template <typename T, size_t N>
void DisplayHelper::display(const T (&array)[N],
                            const std::string& name,
                            const std::string& delimiter) {
    if (!name.empty()) {
        std::cout << name << ": ";
    }

    for (size_t i = 0; i < N; ++i) {
        std::cout << array[i] << delimiter;
    }
    std::cout << "\n";
}

// 针对二维C风格数组的特化
template <typename T, size_t Rows, size_t Cols>
void DisplayHelper::display(const T (&matrix)[Rows][Cols],
                            const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ":\n";
    }

    for (size_t i = 0; i < Rows; ++i) {
        std::cout << "  ";
        for (size_t j = 0; j < Cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// 针对std::pair的显示
template <typename T1, typename T2>
void DisplayHelper::display(const std::pair<T1, T2>& pair,
                            const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ": ";
    }
    std::cout << "(" << pair.first << ", " << pair.second << ")\n";
}

// 针对map的显示
template <typename Key, typename Value>
void DisplayHelper::display_map(const std::map<Key, Value>& map,
                                const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ":\n";
    }

    for (const auto& [key, value] : map) {
        std::cout << "  " << key << " -> " << value << "\n";
    }
}

// 针对set的显示
template <typename T>
void DisplayHelper::display_set(const std::set<T>& set,
                                const std::string& name) {
    display(set, name);
}

// 显示带索引的序列
template <typename Iterable>
void DisplayHelper::display_with_index(const Iterable& iterable,
                                       const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ":\n";
    }

    size_t index = 0;
    for (const auto& element : iterable) {
        std::cout << "  [" << index << "] = " << element << "\n";
        ++index;
    }
}

// 显示bitset
template <size_t N>
void DisplayHelper::display(const std::bitset<N>& bits,
                            const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ": ";
    }
    std::cout << bits.to_string() << " (decimal: " << bits.to_ulong() << ")\n";
}

#endif // DISPLAYHELPER_TPP