//
//  main.cpp
//  52. N皇后 II
//
//  Created by SeacenLiu on 2019/3/27.
//  Copyright © 2019 成. All rights reserved.
//

/**
 n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 
 [](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png)
 
 上图为 8 皇后问题的一种解法。
 
 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 
 示例:
 
 输入: 4
 输出: 2
 解释: 4 皇后问题存在如下两个不同的解法。
 [
 [".Q..",  // 解法 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // 解法 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 */

/**
 - 二维思路
 - 一维思路
 */

#include <iostream>
#include <vector>
using namespace std;

static string toString(int idx, int total) {
    string ret = "";
    for (int i = 0; i < total; i++) {
        if (i == idx) {
            ret += "Q";
        } else {
            ret += ".";
        }
    }
    return ret;
}

static vector<string> toVectorString(vector<int> cur, int total) {
    vector<string> ret = {};
    for (auto i: cur) {
        ret.push_back(toString(i, total));
    }
    return ret;
}

class Solution {
private:
    int res = 0;
    void backtracking(int n, vector<int> temp) {
        if (temp.size() == n) {
            res += 1;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (checkColumShouldSkip(temp, col, n) ||
                checkBiasShouldSkip(temp, col, n)) {
                continue;
            }
            temp.push_back(col);
            backtracking(n, temp);
            temp.pop_back();
        }
    }
    bool checkColumShouldSkip(vector<int> &temp, int target, int total) {
        for (auto x: temp) {
            if (target == x) return true;
        }
        return false;
    }
    bool checkBiasShouldSkip(vector<int> &temp, int target, int total) {
        if (temp.size() == 0) return false;
        int x, y;
        for (int i = 0; i < temp.size(); i++) {
            x = temp[i] + ((int)temp.size() - i);
            y = temp[i] - ((int)temp.size() - i);
            if (target == x || target == y) return true;
        }
        return false;
    }
    
public:
    int totalNQueens(int n) {
        vector<int> temp = {};
        backtracking(n, temp);
        return res;
    }
};

/// 二维思路
class Solution2 {
private:
    int res = 0;
    vector<vector<vector<char>>> resArr;
    bool checkColum(int i, int j, vector<vector<char>>& board, int n) {
        for (int k = 0; k < n; ++k) {
            if (board[k][j] == 'Q')
                return false;
        }
        return true;
    }
    bool checkSlash(int i, int j, vector<vector<char>>& board, int n)  {
        int minN = i <= j ? i : j;
        // 右斜线
        int i1 = i - minN;
        int j1 = j - minN;
        for (; i1 < n && j1 < n; ++i1,++j1) {
            if (board[i1][j1] == 'Q')
                return false;
        }
        // 左斜线
        for (int i2 = i, j2 = j; i2 >= 0 && j2 < n; --i2,++j2) {
            if (board[i2][j2] == 'Q')
                return false;
        }
        for (int i2 = i, j2 = j; i2 < n && j2 >= 0; ++i2,--j2) {
            if (board[i2][j2] == 'Q')
                return false;
        }
        return true;
    }
    void f(int curLayer, vector<vector<char>>& board, int n) {
        if (curLayer == n) {
            ++res;
            resArr.push_back(board);
            return;
        }
        if (curLayer > n)
            return;
        // 检查行 不需要
        // 检查列 && 检查斜线
        for (int col = 0; col < n; ++col) {
            if (!checkColum(curLayer, col, board, n) ||
                !checkSlash(curLayer, col, board, n)) {
                continue;
            }
            // 放一个Q
            board[curLayer][col] = 'Q';
            // 下一行
            f(curLayer+1, board, n);
            // 回溯
            board[curLayer][col] = '.';
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        f(0, board, n);
        for (auto matix: resArr) {
            cout << "--------" << endl;
            for (auto a: matix) {
                for (auto b: a) {
                    cout << b << " ";
                }
                cout << endl;
            }
            cout << "--------" << endl;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.totalNQueens(4) << endl; // 2
    return 0;
}

