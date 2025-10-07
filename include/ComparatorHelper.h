#ifndef LEETCODE_COMPARATORHELPER_H
#define LEETCODE_COMPARATOR_H

#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <unordered_map>
#include <iomanip>
#include <tuple>
#include <type_traits>

using namespace std;

// ============================================================================
// 重载vector输出操作符（放在文件开头）
// ============================================================================

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& matrix) {
    os << "[";
    for (size_t i = 0; i < matrix.size(); i++) {
        os << "[";
        for (size_t j = 0; j < matrix[i].size(); j++) {
            os << matrix[i][j];
            if (j != matrix[i].size() - 1) os << ", ";
        }
        os << "]";
        if (i != matrix.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

// ============================================================================
// RandomGenerator 类
// ============================================================================

class RandomGenerator {
private:
    static mt19937& get_generator();

public:
    static int random_int(int min, int max);
    static vector<int> random_array(int size, int min_val, int max_val);
    static vector<int> random_binary_array(int size);
    static vector<vector<int>> random_2d_array(int rows, int cols, int min_val, int max_val);
    static string random_string(int length, const string& charset = "abcdefghijklmnopqrstuvwxyz");
};

// ============================================================================
// UniversalComparator 模板类（包含实现）
// ============================================================================

template<typename ResultType, typename... Args>
class UniversalComparator {
private:
    function<ResultType(Args...)> func1;
    function<ResultType(Args...)> func2;
    string func1_name;
    string func2_name;
    function<tuple<Args...>(int)> param_generator;

    struct TestStats {
        int total_tests;
        int correct_count;
        int wrong_count;
        double accuracy;
    } stats;

    // 打印参数辅助函数
    template<typename Tuple, size_t... Is>
    void print_tuple_impl(const Tuple& t, index_sequence<Is...>) {
        ((cout << (Is == 0 ? "" : ", ") << get<Is>(t)), ...);
    }

    template<typename... Ts>
    void print_tuple(const tuple<Ts...>& t) {
        print_tuple_impl(t, index_sequence_for<Ts...>{});
    }

    void print_params(const tuple<Args...>& params) {
        cout << "参数: ";
        print_tuple(params);
        cout << endl;
    }

public:
    // 构造函数
    UniversalComparator(function<ResultType(Args...)> f1,
                        function<ResultType(Args...)> f2,
                        function<tuple<Args...>(int)> param_gen,
                        string name1 = "Function1",
                        string name2 = "Function2")
        : func1(f1), func2(f2), param_generator(param_gen),
          func1_name(name1), func2_name(name2), stats{0, 0, 0, 0.0} {}

    // 单次测试
    bool single_test(int test_id, bool verbose = false) {
        try {
            auto params = param_generator(test_id);
            auto apply_func = [](auto&& func, auto&& tuple_args) {
                return apply(forward<decltype(func)>(func), forward<decltype(tuple_args)>(tuple_args));
            };

            ResultType result1 = apply_func(func1, params);
            ResultType result2 = apply_func(func2, params);

            bool correct = (result1 == result2);

            if (verbose || !correct) {
                cout << "测试用例 " << test_id << ": ";
                print_params(params);
                cout << func1_name << " 结果: " << result1 << endl;
                cout << func2_name << " 结果: " << result2 << endl;
                cout << (correct ? "✓ 正确" : "✗ 错误") << endl;
                cout << "---" << endl;
            }

            return correct;
        } catch (const exception& e) {
            if (verbose) {
                cout << "测试用例 " << test_id << " 执行异常: " << e.what() << endl;
            }
            return false;
        }
    }

    // 批量随机测试
    void batch_test(int total_tests, int verbose_interval = 100) {
        stats = {total_tests, 0, 0, 0.0};

        cout << "开始批量测试..." << endl;
        cout << "测试次数: " << total_tests << endl;
        cout << "==========================================" << endl;

        for (int i = 0; i < total_tests; i++) {
            bool correct = single_test(i, false);

            if (correct) {
                stats.correct_count++;
            } else {
                stats.wrong_count++;
                single_test(i, true);
            }

            if ((i + 1) % verbose_interval == 0) {
                cout << "已完成 " << (i + 1) << " 次测试" << endl;
            }
        }

        stats.accuracy = static_cast<double>(stats.correct_count) / total_tests;

        cout << "==========================================" << endl;
        cout << "测试完成！" << endl;
        cout << "总测试次数: " << stats.total_tests << endl;
        cout << "正确次数: " << stats.correct_count << endl;
        cout << "错误次数: " << stats.wrong_count << endl;
        cout << fixed << setprecision(4);
        cout << func1_name << " 的准确率: " << stats.accuracy * 100 << "%" << endl;
    }

    TestStats get_stats() const { return stats; }
};

// ============================================================================
// ComparatorFactory 类
// ============================================================================

class ComparatorFactory {
public:
    static UniversalComparator<int, vector<int>> create_single_param_comparator(
            function<int(const vector<int>&)> f1,
            function<int(const vector<int>&)> f2,
            int min_size, int max_size, int min_val, int max_val,
            string name1 = "Solver", string name2 = "Checker");

    static UniversalComparator<int, vector<vector<int>>> create_2d_param_comparator(
            function<int(const vector<vector<int>>&)> f1,
            function<int(const vector<vector<int>>&)> f2,
            int min_rows, int max_rows, int min_cols, int max_cols, int min_val, int max_val,
            string name1 = "Solver", string name2 = "Checker");

    static UniversalComparator<int, int, vector<int>, string> create_multi_param_comparator(
            function<int(int, const vector<int>&, const string&)> f1,
            function<int(int, const vector<int>&, const string&)> f2,
            string name1 = "Solver", string name2 = "Checker");

    template<typename ResultType, typename... Args>
    static UniversalComparator<ResultType, Args...> create_custom_comparator(
            function<ResultType(Args...)> f1,
            function<ResultType(Args...)> f2,
            function<tuple<Args...>(int)> param_gen,
            string name1 = "Solver", string name2 = "Checker") {
        return UniversalComparator<ResultType, Args...>(f1, f2, param_gen, name1, name2);
    }
};

// ============================================================================
// ExampleSolutions 类
// ============================================================================

class ExampleSolutions {
public:
    static int solver_single(const vector<int>& nums);
    static int checker_single(const vector<int>& nums);
    static int solver_2d(const vector<vector<int>>& matrix);
    static int checker_2d(const vector<vector<int>>& matrix);
    static int solver_multi(int n, const vector<int>& arr, const string& s);
    static int checker_multi(int n, const vector<int>& arr, const string& s);
};

#endif // LEETCODE_COMPARATORHELPER_H
