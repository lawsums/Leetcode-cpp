#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    int n, m, cnt;
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> block;

public:
    Solution() : n(9), m(9), cnt(0) {
        row.assign(9, vector<int>(10, 0)); // 行索引0-8，数字索引1-9
        col.assign(9, vector<int>(10, 0));
        block.assign(9, vector<int>(10, 0));
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    int blockIndex = 3 * (i / 3) + j / 3;
                    block[blockIndex][num] = 1;
                }
            }
        }
        dfs(0, 0, board);
        cout << cnt << endl;
    }

    bool dfs(int r, int c, vector<vector<char>>& board) {
        cnt++;
        if (r == n) {
            return true; // 所有单元格处理完毕
        }

        auto nextPos = next_pos(r, c);
        int nr = nextPos.first, nc = nextPos.second;

        if (board[r][c] != '.') {
            return dfs(nr, nc, board);
        }

        int blockIndex = 3 * (r / 3) + c / 3;
        for (int num = 1; num <= 9; num++) {
            if (!row[r][num] && !col[c][num] && !block[blockIndex][num]) {
                row[r][num] = 1;
                col[c][num] = 1;
                block[blockIndex][num] = 1;
                board[r][c] = '0' + num;

                if (dfs(nr, nc, board)) {
                    return true;
                }

                row[r][num] = 0;
                col[c][num] = 0;
                block[blockIndex][num] = 0;
                board[r][c] = '.';
            }
        }
        return false;
    }

    pair<int, int> next_pos(int r, int c) {
        if (c + 1 == m) {
            return {r + 1, 0};
        } else {
            return {r, c + 1};
        }
    }
};

int main() {
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    Solution().solveSudoku(board);

    // 打印结果
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}