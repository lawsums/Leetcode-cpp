//
// Created by Hello on 2025/9/25.
//

#ifndef LEETCODE_RANDOMHELPER_H
#define LEETCODE_RANDOMHELPER_H

// RandomHelper.h
#include <random>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>

class RandomHelper {
private:
    static std::mt19937& get_generator();

public:
    // ==================== 基础随机数生成 ====================

    /// @brief 生成指定范围内的随机整数
    /// @param min 最小值（包含）
    /// @param max 最大值（包含）
    /// @return 随机整数
    static int random_int(int min, int max);

    /// @brief 生成指定范围内的随机长整数
    /// @param min 最小值（包含）
    /// @param max 最大值（包含）
    /// @return 随机长整数
    static long long random_long(long long min, long long max);

    /// @brief 生成随机布尔值
    /// @param true_probability 为true的概率（0.0-1.0）
    /// @return 随机布尔值
    static bool random_bool(double true_probability = 0.5);

    /// @brief 生成指定范围内的随机浮点数
    /// @param min 最小值（包含）
    /// @param max 最大值（包含）
    /// @return 随机浮点数
    static double random_double(double min, double max);

    /// @brief 生成随机字符
    /// @param charset 字符集，默认为字母数字
    /// @return 随机字符
    static char random_char(const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    // ==================== 数组/向量生成 ====================

    /// @brief 生成随机整数数组
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 随机整数数组
    static std::vector<int> random_array(int size, int min_val, int max_val);

    /// @brief 生成随机长整数数组
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 随机长整数数组
    static std::vector<long long> random_long_array(int size, long long min_val, long long max_val);

    /// @brief 生成随机浮点数数组
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 随机浮点数数组
    static std::vector<double> random_double_array(int size, double min_val, double max_val);

    /// @brief 生成随机布尔数组
    /// @param size 数组大小
    /// @param true_probability 为true的概率
    /// @return 随机布尔数组
    static std::vector<bool> random_bool_array(int size, double true_probability = 0.5);

    /// @brief 生成0-1二进制数组
    /// @param size 数组大小
    /// @return 二进制数组
    static std::vector<int> random_binary_array(int size);

    /// @brief 生成已排序的随机数组（升序）
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 已排序的随机数组
    static std::vector<int> random_sorted_array(int size, int min_val, int max_val);

    /// @brief 生成已排序且不重复的随机数组（升序）
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 已排序且不重复的随机数组
    static std::vector<int> random_unique_sorted_array(int size, int min_val, int max_val);

    /// @brief 生成不重复的随机数组
    /// @param size 数组大小
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 不重复的随机数组
    static std::vector<int> random_unique_array(int size, int min_val, int max_val);

    /// @brief 生成随机二维数组
    /// @param rows 行数
    /// @param cols 列数
    /// @param min_val 最小值
    /// @param max_val 最大值
    /// @return 随机二维数组
    static std::vector<std::vector<int>> random_2d_array(int rows, int cols, int min_val, int max_val);

    // ==================== 字符串生成 ====================

    /// @brief 生成随机字符串
    /// @param length 字符串长度
    /// @param charset 字符集
    /// @return 随机字符串
    static std::string random_string(int length, const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    /// @brief 生成随机小写字母字符串
    /// @param length 字符串长度
    /// @return 随机小写字母字符串
    static std::string random_lowercase_string(int length);

    /// @brief 生成随机大写字母字符串
    /// @param length 字符串长度
    /// @return 随机大写字母字符串
    static std::string random_uppercase_string(int length);

    /// @brief 生成随机字母字符串
    /// @param length 字符串长度
    /// @return 随机字母字符串
    static std::string random_alpha_string(int length);

    /// @brief 生成随机数字字符串
    /// @param length 字符串长度
    /// @return 随机数字字符串
    static std::string random_digit_string(int length);

    /// @brief 生成随机字母数字字符串
    /// @param length 字符串长度
    /// @return 随机字母数字字符串
    static std::string random_alphanumeric_string(int length);

    /// @brief 生成随机单词（以空格分隔的字符串）
    /// @param word_count 单词数量
    /// @param min_word_len 最小单词长度
    /// @param max_word_len 最大单词长度
    /// @return 随机单词字符串
    static std::string random_words(int word_count, int min_word_len = 3, int max_word_len = 10);

    // ==================== 特殊数据结构生成 ====================

    /// @brief 生成随机pair
    /// @param min_first 第一个元素最小值
    /// @param max_first 第一个元素最大值
    /// @param min_second 第二个元素最小值
    /// @param max_second 第二个元素最大值
    /// @return 随机pair
    static std::pair<int, int> random_pair(int min_first, int max_first, int min_second, int max_second);

    /// @brief 生成随机pair数组
    /// @param size 数组大小
    /// @param min_first 第一个元素最小值
    /// @param max_first 第一个元素最大值
    /// @param min_second 第二个元素最小值
    /// @param max_second 第二个元素最大值
    /// @return 随机pair数组
    static std::vector<std::pair<int, int>> random_pair_array(int size,
                                                              int min_first, int max_first, int min_second, int max_second);

    /// @brief 生成随机三元组
    /// @param min1 第一个元素最小值
    /// @param max1 第一个元素最大值
    /// @param min2 第二个元素最小值
    /// @param max2 第二个元素最大值
    /// @param min3 第三个元素最小值
    /// @param max3 第三个元素最大值
    /// @return 随机三元组
    static std::tuple<int, int, int> random_triple(int min1, int max1, int min2, int max2, int min3, int max3);

    // ==================== 算法测试专用生成器 ====================

    /// @brief 生成图测试数据（邻接表形式）
    /// @param node_count 节点数量
    /// @param edge_probability 边存在的概率
    /// @param min_weight 边权重最小值
    /// @param max_weight 边权重最大值
    /// @param directed 是否为有向图
    /// @return 邻接表表示的图
    static std::vector<std::vector<std::pair<int, int>>> random_graph_data(
            int node_count, double edge_probability = 0.3,
            int min_weight = 1, int max_weight = 10, bool directed = false);



    // ==================== 工具函数 ====================

    /// @brief 设置随机种子（用于重现测试用例）
    /// @param seed 随机种子
    static void set_seed(unsigned int seed);

    /// @brief 从数组中随机选择一个元素
    /// @tparam T 元素类型
    /// @param arr 数组
    /// @return 随机选择的元素
    template<typename T>
    static T random_choice(const std::vector<T>& arr) {
        if (arr.empty()) return T();
        std::uniform_int_distribution<int> dist(0, arr.size() - 1);
        return arr[dist(get_generator())];
    }

    /// @brief 打乱数组顺序
    /// @tparam T 元素类型
    /// @param arr 要打乱的数组
    template<typename T>
    static void shuffle(std::vector<T>& arr) {
        std::shuffle(arr.begin(), arr.end(), get_generator());
    }

    /// @brief 从数组中随机选择多个不重复的元素
    /// @tparam T 元素类型
    /// @param arr 源数组
    /// @param count 要选择的元素数量
    /// @return 随机选择的元素数组
    template<typename T>
    static std::vector<T> random_sample(const std::vector<T>& arr, int count) {
        if (count >= arr.size()) return arr;
        std::vector<T> result(arr.begin(), arr.end());
        std::shuffle(result.begin(), result.end(), get_generator());
        result.resize(count);
        return result;
    }
};

#endif//LEETCODE_RANDOMHELPER_H
