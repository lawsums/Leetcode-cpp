#ifndef DISPLAYHELPER_H
#define DISPLAYHELPER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <type_traits>
#include <utility>

namespace display {

    // ==================== SFINAE 类型检测工具 ====================
    namespace detail {

        // 检测是否是迭代器容器
        template<typename T, typename = void>
        struct is_iterable : std::false_type {};

        template<typename T>
        struct is_iterable<T, std::void_t<
                                      decltype(std::declval<T>().begin()),
                                      decltype(std::declval<T>().end())
                                      >> : std::true_type {};

        // 检测是否是 std::pair
        template<typename T>
        struct is_pair : std::false_type {};

        template<typename T1, typename T2>
        struct is_pair<std::pair<T1, T2>> : std::true_type {};

        // 检测是否是 std::tuple
        template<typename T>
        struct is_tuple : std::false_type {};

        template<typename... Args>
        struct is_tuple<std::tuple<Args...>> : std::true_type {};

        // 检测是否是 std::string
        template<typename T>
        struct is_string : std::false_type {};

        template<>
        struct is_string<std::string> : std::true_type {};

        template<>
        struct is_string<const char*> : std::true_type {};

        template<size_t N>
        struct is_string<char[N]> : std::true_type {};

    } // namespace detail

    // ==================== 显示实现函数 ====================
    namespace detail {

        // 基础显示函数 - 处理基本类型（使用SFINAE排除容器、pair、tuple、字符串）
        template<typename T>
        auto display_impl(const T& value, std::ostream& os)
                -> std::enable_if_t<!is_iterable<T>::value &&
                                    !is_pair<T>::value &&
                                    !is_tuple<T>::value &&
                                    !is_string<T>::value>
        {
            os << value;
        }

        // 显示字符串（加引号）
        void display_impl(const std::string& value, std::ostream& os) {
            os << "\"" << value << "\"";
        }

        void display_impl(const char* value, std::ostream& os) {
            os << "\"" << value << "\"";
        }

        // 显示字符（加单引号）
        void display_impl(char value, std::ostream& os) {
            os << "'" << value << "'";
        }

        // 显示bool（true/false）
        void display_impl(bool value, std::ostream& os) {
            os << (value ? "true" : "false");
        }

        // 显示pair
        template<typename T1, typename T2>
        void display_impl(const std::pair<T1, T2>& pair, std::ostream& os) {
            os << "(";
            display_impl(pair.first, os);
            os << ", ";
            display_impl(pair.second, os);
            os << ")";
        }

        // 显示tuple
        template<typename... Args, size_t... Is>
        void display_tuple_impl(const std::tuple<Args...>& tuple,
                                std::ostream& os,
                                std::index_sequence<Is...>) {
            os << "(";
            ((os << (Is == 0 ? "" : ", "), display_impl(std::get<Is>(tuple), os)), ...);
            os << ")";
        }

        template<typename... Args>
        void display_impl(const std::tuple<Args...>& tuple, std::ostream& os) {
            display_tuple_impl(tuple, os, std::make_index_sequence<sizeof...(Args)>{});
        }

        // 显示迭代器容器（使用SFINAE确保只对迭代器容器有效）
        template<typename Iterable>
        auto display_impl(const Iterable& iterable, std::ostream& os)
                -> std::enable_if_t<is_iterable<Iterable>::value &&
                                    !is_pair<Iterable>::value &&
                                    !is_tuple<Iterable>::value &&
                                    !is_string<Iterable>::value>
        {
            os << "[";
            bool first = true;
            for (const auto& element : iterable) {
                if (!first) os << ", ";
                display_impl(element, os);
                first = false;
            }
            os << "]";
        }

        // 显示bitset
        template<size_t N>
        void display_impl(const std::bitset<N>& bits, std::ostream& os) {
            os << "0b" << bits.to_string();
        }

        // 替换字符串中的占位符
        inline std::string replace_placeholder(std::string str,
                                               const std::string& placeholder,
                                               const std::string& replacement) {
            size_t pos = str.find(placeholder);
            if (pos != std::string::npos) {
                str.replace(pos, placeholder.length(), replacement);
            }
            return str;
        }

    } // namespace detail

    // ==================== 公共接口实现 ====================

    // 带分隔符的显示函数
    template<typename... Args>
    void print_delim(const std::string& delimiter, const Args&... args) {
        bool first = true;
        auto print_func = [&](const auto& arg) {
            if (!first) std::cout << delimiter;
            detail::display_impl(arg, std::cout);
            first = false;
        };

        (print_func(args), ...);
        std::cout << std::endl;
    }

    // 主要显示函数：默认空格分隔
    template<typename... Args>
    void print(const Args&... args) {
        print_delim(" ", args...);
    }

    // 命名显示版本：为每个参数提供名称
    template<typename... Args>
    void print_named(const std::vector<std::string>& names, const Args&... args) {
        if (sizeof...(args) != names.size()) {
            std::cerr << "Error: Number of names doesn't match number of arguments" << std::endl;
            return;
        }

        size_t index = 0;
        auto print_func = [&](const auto& arg) {
            std::cout << names[index++] << " = ";
            detail::display_impl(arg, std::cout);
            std::cout << "; ";
        };

        (print_func(args), ...);
        std::cout << std::endl;
    }

    // 格式化显示：类似Python的f-string
    template<typename... Args>
    void print_fmt(const std::string& format, const Args&... args) {
        std::string result = format;
        size_t index = 0;

        // 将参数转换为字符串
        auto to_string = [](const auto& arg) {
            std::ostringstream oss;
            detail::display_impl(arg, oss);
            return oss.str();
        };

        // 替换占位符 {0}, {1}, {2}, ...
        ((result = detail::replace_placeholder(result,
                                               "{" + std::to_string(index++) + "}",
                                               to_string(args))), ...);

        std::cout << result << std::endl;
    }

    // 分隔线（添加默认参数）
    void separator(int length = 40, char ch = '-') {
        std::cout << std::string(length, ch) << std::endl;
    }

    // 基础切片显示
    template<typename T>
    void print_slice(const std::vector<T>& vec, size_t l, size_t r) {
        // 处理边界
        l = std::min(l, vec.size());
        r = std::min(r, vec.size());

        if (l >= r) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::cout << "[";
        for (size_t i = l; i < r; ++i) {
            detail::display_impl(vec[i], std::cout);  // 使用你的display_impl来保持一致性
            if (i < r - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

} // namespace display

#endif // DISPLAYHELPER_H