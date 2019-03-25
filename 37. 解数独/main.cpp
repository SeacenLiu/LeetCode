//
//  main.cpp
//  37. 解数独
//
//  Created by SeacenLiu on 2019/3/25.
//  Copyright © 2019 成. All rights reserved.
//

/**
 编写一个程序，通过已填充的空格来解决数独问题。
 
 一个数独的解法需遵循如下规则：
 
 数字 1-9 在每一行只能出现一次。
 数字 1-9 在每一列只能出现一次。
 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 空白格用 '.' 表示。
 
 [](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
 
 一个数独。
 
 [](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
 
 答案被标成红色。
 
 Note:
 
 给定的数独序列只包含数字 1-9 和字符 '.' 。
 你可以假设给定的数独只有唯一解。
 给定数独永远是 9x9 形式的。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int i, int j, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block,vector<vector<char>>& board) {
        // 找寻空位置
        while (board[i][j] != '.') {
            if (++j >= 9) {
                i++;
                j = 0;
            }
            if (i >= 9) {
                return true;
            }
        }
        // 在(i,j)中加 num
        for (int num = 1; num <= 9; ++num) {
            int blockIndex = i / 3 * 3 + j / 3;
            // 检查行列块中是否已经存在
            if (!row[i][num] && !col[j][num] && !block[blockIndex][num]) {
                // 递归
                board[i][j] = '0' + num;
                row[i][num] = true;
                col[j][num] = true;
                block[blockIndex][num] = true;
                if (dfs(i, j, row, col, block, board)) {
                    return true;
                } else {
                    // 回溯
                    row[i][num] = false;
                    col[j][num] = false;
                    block[blockIndex][num] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 记录某行，某位数字是否已经被摆放
        // 第i行的数字j是否被摆放
        vector<vector<bool>> row(9, vector<bool>(9));
        // 记录某列，某位数字是否已经被摆放
        // 第i列数字j是否被摆放
        vector<vector<bool>> col(9, vector<bool>(9));
        // 记录某 3x3 宫格内，某位数字是否已经被摆放
        // 第i个块数字j是否被摆放
        vector<vector<bool>> block(9, vector<bool>(9));
        // 初始化行列块保存
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    col[j][num] = true;
                    // blockIndex = i / 3 * 3 + j / 3，取整
                    block[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        dfs(0, 0, row, col, block, board);
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<char> a1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> a2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> a3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> a4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> a5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> a6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> a7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> a8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> a9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<vector<char>> a = {a1,a2,a3,a4,a5,a6,a7,a8,a9};
    Solution sol = Solution();
    sol.solveSudoku(a);
    for (auto arr: a) {
        for (auto v: arr) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
