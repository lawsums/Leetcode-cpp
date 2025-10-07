// RandomHelper.cpp (续)
#include "../include/RandomHelper.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

std::mt19937& RandomHelper::get_generator() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
}

void RandomHelper::set_seed(unsigned int seed) {
    get_generator().seed(seed);
}

int RandomHelper::random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(get_generator());
}

long long RandomHelper::random_long(long long min, long long max) {
    std::uniform_int_distribution<long long> dist(min, max);
    return dist(get_generator());
}

bool RandomHelper::random_bool(double true_probability) {
    std::bernoulli_distribution dist(true_probability);
    return dist(get_generator());
}

double RandomHelper::random_double(double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(get_generator());
}

char RandomHelper::random_char(const std::string& charset) {
    std::uniform_int_distribution<int> dist(0, charset.length() - 1);
    return charset[dist(get_generator())];
}

std::vector<int> RandomHelper::random_array(int size, int min_val, int max_val) {
    std::vector<int> result(size);
    std::uniform_int_distribution<int> dist(min_val, max_val);
    for (int i = 0; i < size; i++) {
        result[i] = dist(get_generator());
    }
    return result;
}

std::vector<long long> RandomHelper::random_long_array(int size, long long min_val, long long max_val) {
    std::vector<long long> result(size);
    std::uniform_int_distribution<long long> dist(min_val, max_val);
    for (int i = 0; i < size; i++) {
        result[i] = dist(get_generator());
    }
    return result;
}

std::vector<double> RandomHelper::random_double_array(int size, double min_val, double max_val) {
    std::vector<double> result(size);
    std::uniform_real_distribution<double> dist(min_val, max_val);
    for (int i = 0; i < size; i++) {
        result[i] = dist(get_generator());
    }
    return result;
}

std::vector<bool> RandomHelper::random_bool_array(int size, double true_probability) {
    std::vector<bool> result(size);
    std::bernoulli_distribution dist(true_probability);
    for (int i = 0; i < size; i++) {
        result[i] = dist(get_generator());
    }
    return result;
}

std::vector<int> RandomHelper::random_binary_array(int size) {
    return random_array(size, 0, 1);
}

std::vector<int> RandomHelper::random_sorted_array(int size, int min_val, int max_val) {
    auto result = random_array(size, min_val, max_val);
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<int> RandomHelper::random_unique_sorted_array(int size, int min_val, int max_val) {
    if (max_val - min_val + 1 < size) {
        max_val = min_val + size - 1;
    }

    std::vector<int> result;
    for (int i = min_val; i <= max_val && result.size() < size; i++) {
        result.push_back(i);
    }

    shuffle(result);
    result.resize(size);
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<int> RandomHelper::random_unique_array(int size, int min_val, int max_val) {
    if (max_val - min_val + 1 < size) {
        max_val = min_val + size - 1;
    }

    std::vector<int> result;
    for (int i = min_val; i <= max_val && result.size() < size; i++) {
        result.push_back(i);
    }

    shuffle(result);
    result.resize(size);
    return result;
}

std::vector<std::vector<int>> RandomHelper::random_2d_array(int rows, int cols, int min_val, int max_val) {
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
    std::uniform_int_distribution<int> dist(min_val, max_val);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = dist(get_generator());
        }
    }
    return result;
}

std::string RandomHelper::random_string(int length, const std::string& charset) {
    std::string result;
    std::uniform_int_distribution<int> dist(0, charset.length() - 1);
    for (int i = 0; i < length; i++) {
        result += charset[dist(get_generator())];
    }
    return result;
}

std::string RandomHelper::random_lowercase_string(int length) {
    return random_string(length, "abcdefghijklmnopqrstuvwxyz");
}

std::string RandomHelper::random_uppercase_string(int length) {
    return random_string(length, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

std::string RandomHelper::random_alpha_string(int length) {
    return random_string(length, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

std::string RandomHelper::random_digit_string(int length) {
    return random_string(length, "0123456789");
}

std::string RandomHelper::random_alphanumeric_string(int length) {
    return random_string(length, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}

std::string RandomHelper::random_words(int word_count, int min_word_len, int max_word_len) {
    std::string result;
    for (int i = 0; i < word_count; i++) {
        if (i > 0) result += " ";
        int word_len = random_int(min_word_len, max_word_len);
        result += random_lowercase_string(word_len);
    }
    return result;
}

std::pair<int, int> RandomHelper::random_pair(int min_first, int max_first, int min_second, int max_second) {
    return {random_int(min_first, max_first), random_int(min_second, max_second)};
}

std::vector<std::pair<int, int>> RandomHelper::random_pair_array(int size,
                                                                 int min_first, int max_first, int min_second, int max_second) {

    std::vector<std::pair<int, int>> result;
    for (int i = 0; i < size; i++) {
        result.push_back(random_pair(min_first, max_first, min_second, max_second));
    }
    return result;
}

std::tuple<int, int, int> RandomHelper::random_triple(int min1, int max1, int min2, int max2, int min3, int max3) {
    return {random_int(min1, max1), random_int(min2, max2), random_int(min3, max3)};
}

std::vector<std::vector<std::pair<int, int>>> RandomHelper::random_graph_data(
        int node_count, double edge_probability, int min_weight, int max_weight, bool directed) {

    std::vector<std::vector<std::pair<int, int>>> graph(node_count);

    for (int i = 0; i < node_count; i++) {
        for (int j = (directed ? 0 : i + 1); j < node_count; j++) {
            if (i != j && random_bool(edge_probability)) {
                int weight = random_int(min_weight, max_weight);
                graph[i].push_back({j, weight});
                if (!directed) {
                    graph[j].push_back({i, weight});
                }
            }
        }
    }
    return graph;
}

//int main() {
    // 设置随机种子（可选，用于重现测试）
//    RandomHelper::set_seed(42);

//    // 基础类型测试
//    cout << "随机整数: " << RandomHelper::random_int(1, 100) << endl;
//    cout << "随机布尔: " << RandomHelper::random_bool(0.3) << endl;
//    cout << "随机浮点数: " << RandomHelper::random_double(0.0, 1.0) << endl;
//
//    // 数组测试
//    auto arr = RandomHelper::random_array(5, 1, 10);
//    cout << "随机数组: ";
//    for (int num : arr) cout << num << " ";
//    cout << endl;
//
//    auto sorted_arr = RandomHelper::random_sorted_array(5, 1, 10);
//    cout << "排序数组: ";
//    for (int num : sorted_arr) cout << num << " ";
//    cout << endl;
//
//    // 字符串测试
//    cout << "随机字符串: " << RandomHelper::random_string(10) << endl;
//    cout << "随机单词: " << RandomHelper::random_words(3) << endl;
//
//    // 特殊数据结构测试
//    auto pairs = RandomHelper::random_pair_array(3, 1, 10, 1, 10);
//    cout << "随机pair数组: ";
//    for (auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
//    cout << endl;
//
//    // 算法数据结构测试
//    auto tree_data = RandomHelper::random_binary_tree_data(10, 1, 100, 0.1);
//    cout << "二叉树数据: ";
//    for (int val : tree_data) cout << val << " ";
//    cout << endl;
//
//    // 工具函数测试
//    vector<int> sample_arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << "随机选择: " << RandomHelper::random_choice(sample_arr) << endl;
//
//    auto sample = RandomHelper::random_sample(sample_arr, 3);
//    cout << "随机采样: ";
//    for (int num : sample) cout << num << " ";
//    cout << endl;
//
//    return 0;
//}