#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//private:
//    bool md_rows[9][9] = {false}; // 行使用标记
//    bool md_cols[9][9] = {false}; // 列使用标记
//    bool md_blocks[9][9] = {false}; // 块使用标记
//
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        // 初始化已填数字的信息
//        for (int i = 0; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                if (board[i][j] != '.') {
//                    int num = board[i][j] - '1'; // 转换为0~8的索引
//                    md_rows[i][num] = true;
//                    md_cols[j][num] = true;
//                    int block_index = (i / 3) * 3 + (j / 3);
//                    md_blocks[block_index][num] = true;
//                }
//            }
//        }
//
//        // 从(0,0)开始回溯
//        backtrack(board, 0, 0);
//    }
//
//private:
//    bool backtrack(vector<vector<char>>& board, int r, int c) {
//        if (r == 9) { // 所有行都填完了
//            return true;
//        }
//
//        int next_r = r;
//        int next_c = c + 1;
//        if (next_c == 9) { // 当前行填完，换下一行
//            next_r += 1;
//            next_c = 0;
//        }
//
//        if (board[r][c] != '.') { // 已经填了，跳过
//            return backtrack(board, next_r, next_c);
//        }
//
//        int block_index = (r / 3) * 3 + (c / 3);
//        for (int num = 0; num < 9; num++) { // 尝试数字0~8（对应1~9）
//            // 检查该数字是否可以填入当前格子
//            if (!md_rows[r][num] && !md_cols[c][num] && !md_blocks[block_index][num]) {
//                // 做选择
//                board[r][c] = '1' + num;
//                md_rows[r][num] = true;
//                md_cols[c][num] = true;
//                md_blocks[block_index][num] = true;
//
//                // 继续下一个格子
//                if (backtrack(board, next_r, next_c)) {
//                    return true;
//                }
//
//                // 撤销选择
//                board[r][c] = '.';
//                md_rows[r][num] = false;
//                md_cols[c][num] = false;
//                md_blocks[block_index][num] = false;
//            }
//        }
//
//        return false; // 所有数字都不合适，回溯
//    }
//};

//// 测试代码
//int main() {
//    vector<vector<char>> board = {
//            {'5','3','.','.','7','.','.','.','.'},
//            {'6','.','.','1','9','5','.','.','.'},
//            {'.','9','8','.','.','.','.','6','.'},
//            {'8','.','.','.','6','.','.','.','3'},
//            {'4','.','.','8','.','3','.','.','1'},
//            {'7','.','.','.','2','.','.','.','6'},
//            {'.','6','.','.','.','.','2','8','.'},
//            {'.','.','.','4','1','9','.','.','5'},
//            {'.','.','.','.','8','.','.','7','9'}
//    };
//
//    Solution solution;
//    solution.solveSudoku(board);
//
//    // 打印结果
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < 9; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

class Solution {
private:
    int n, m, cnt;
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> block;

public:
    Solution() : n(9), m(9), cnt(0) {
        row.assign(9, vector<int>(9, 0)); // 改为9个元素（0-8）
        col.assign(9, vector<int>(9, 0));
        block.assign(9, vector<int>(9, 0));
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1'; // 改为减'1'
                    row[i][num] = 1;
                    col[j][num] = 1;
                    int blockIndex = 3 * (i / 3) + j / 3;
                    block[blockIndex][num] = 1;
                }
            }
        }
        dfs(0, 0, board);
    }

    bool dfs(int r, int c, vector<vector<char>>& board) {
        if (r == n) return true;

        auto nextPos = next_pos(r, c);
        int nr = nextPos.first, nc = nextPos.second;

        if (board[r][c] != '.') return dfs(nr, nc, board);

        int blockIndex = 3 * (r / 3) + c / 3;
        for (int num = 0; num < 9; num++) { // 改为0-8
            if (!row[r][num] && !col[c][num] && !block[blockIndex][num]) {
                row[r][num] = 1;
                col[c][num] = 1;
                block[blockIndex][num] = 1;
                board[r][c] = '1' + num; // 改为'1' + num

                if (dfs(nr, nc, board)) return true;

                row[r][num] = 0;
                col[c][num] = 0;
                block[blockIndex][num] = 0;
                board[r][c] = '.';
            }
        }
        return false;
    }

    pair<int, int> next_pos(int r, int c) {
        if (c + 1 == m) return {r + 1, 0};
        else return {r, c + 1};
    }
};