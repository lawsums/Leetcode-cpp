#include "ComparatorHelper.h"
#include <random>

using namespace std;

// ============================================================================
// RandomGenerator 实现
// ============================================================================

mt19937& RandomGenerator::get_generator() {
    static random_device rd;
    static mt19937 gen(rd());
    return gen;
}

int RandomGenerator::random_int(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(get_generator());
}

vector<int> RandomGenerator::random_array(int size, int min_val, int max_val) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = random_int(min_val, max_val);
    }
    return arr;
}

vector<int> RandomGenerator::random_binary_array(int size) {
    return random_array(size, 0, 1);
}

vector<vector<int>> RandomGenerator::random_2d_array(int rows, int cols, int min_val, int max_val) {
    vector<vector<int>> arr(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = random_int(min_val, max_val);
        }
    }
    return arr;
}

string RandomGenerator::random_string(int length, const string& charset) {
    uniform_int_distribution<int> dist(0, charset.length() - 1);
    string result;
    for (int i = 0; i < length; i++) {
        result += charset[dist(get_generator())];
    }
    return result;
}

// ============================================================================
// ComparatorFactory 实现
// ============================================================================

UniversalComparator<int, vector<int>> ComparatorFactory::create_single_param_comparator(
        function<int(const vector<int>&)> f1,
        function<int(const vector<int>&)> f2,
        int min_size, int max_size, int min_val, int max_val,
        string name1, string name2) {

    auto param_gen = [=](int test_id) {
        int size = RandomGenerator::random_int(min_size, max_size);
        return make_tuple(RandomGenerator::random_array(size, min_val, max_val));
    };

    return UniversalComparator<int, vector<int>>(f1, f2, param_gen, name1, name2);
}

UniversalComparator<int, vector<vector<int>>> ComparatorFactory::create_2d_param_comparator(
        function<int(const vector<vector<int>>&)> f1,
        function<int(const vector<vector<int>>&)> f2,
        int min_rows, int max_rows, int min_cols, int max_cols, int min_val, int max_val,
        string name1, string name2) {

    auto param_gen = [=](int test_id) {
        int rows = RandomGenerator::random_int(min_rows, max_rows);
        int cols = RandomGenerator::random_int(min_cols, max_cols);
        return make_tuple(RandomGenerator::random_2d_array(rows, cols, min_val, max_val));
    };

    return UniversalComparator<int, vector<vector<int>>>(f1, f2, param_gen, name1, name2);
}

UniversalComparator<int, int, vector<int>, string> ComparatorFactory::create_multi_param_comparator(
        function<int(int, const vector<int>&, const string&)> f1,
        function<int(int, const vector<int>&, const string&)> f2,
        string name1, string name2) {

    auto param_gen = [](int test_id) {
        int param1 = RandomGenerator::random_int(1, 100);
        vector<int> param2 = RandomGenerator::random_array(10, 0, 1);
        string param3 = RandomGenerator::random_string(5);
        return make_tuple(param1, param2, param3);
    };

    return UniversalComparator<int, int, vector<int>, string>(f1, f2, param_gen, name1, name2);
}

// ============================================================================
// ExampleSolutions 实现
// ============================================================================

int ExampleSolutions::solver_single(const vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    return sum;
}

int ExampleSolutions::checker_single(const vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    return sum;
}

int ExampleSolutions::solver_2d(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (const auto& row : matrix) {
        for (int val : row) {
            sum += val;
        }
    }
    return sum;
}

int ExampleSolutions::checker_2d(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (const auto& row : matrix) {
        for (int val : row) {
            sum += val;
        }
    }
    return sum;
}

int ExampleSolutions::solver_multi(int n, const vector<int>& arr, const string& s) {
    return n + arr.size() + s.length();
}

int ExampleSolutions::checker_multi(int n, const vector<int>& arr, const string& s) {
    return n + arr.size() + s.length();
}
