//
//  main.cpp
//  N皇后
//
//  Created by SeacenLiu on 2018/8/1.
//  Copyright © 2018年 成. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 
 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 
 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 
 示例:
 
 输入: 4
 输出: [
 [".Q..",  // 解法 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // 解法 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 解释: 4 皇后问题存在两个不同的解法。
 */

/// 8ms
/**
class Solution {
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string>cur(n, string(n,'.'));
        helper(cur, 0);
        return res;
    }
    void helper(vector<string> &cur, int row)
    {
        if(row == cur.size())
        {
            res.push_back(cur);
            return;
        }
        for(int col = 0; col < cur.size(); col++)
            if(isValid(cur, row, col))
            {
                cur[row][col] = 'Q';
                helper(cur, row+1);
                cur[row][col] = '.';
            }
    }
    
    //判断在cur[row][col]位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<string> &cur, int row, int col)
    {
        //列
        for(int i = 0; i < row; i++)
            if(cur[i][col] == 'Q')return false;
        //右对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)
        for(int i = row-1, j=col-1; i >= 0 && j >= 0; i--,j--)
            if(cur[i][j] == 'Q')return false;
        //左对角线(只需要判断对角线上半部分，因为后面的行还没有开始放置)
        for(int i = row-1, j=col+1; i >= 0 && j < cur.size(); i--,j++)
            if(cur[i][j] == 'Q')return false;
        return true;
    }
};
 */

class Solution {
private:
    vector<vector<string>> ret = {};
    void backtracking(int n, vector<int> temp) {
        if (temp.size() == n) {
            ret.push_back(toVectorString(temp, n));
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
    
    vector<string> toVectorString(vector<int> cur, int total) {
        vector<string> ret = {};
        for (auto i: cur) {
            ret.push_back(toString(i, total));
        }
        return ret;
    }
    
    string toString(int idx, int total) {
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
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp = {};
        backtracking(n, temp);
        return ret;
    }
};

/** 220ms 优化空间巨大
class Solution {
private:
    vector<vector<string>> ret = {};
    void backtracking(int n, int curIdx, vector<int> temp) {
        if (temp.size() == n) {
            ret.push_back(toVectorString(temp, n));
            return;
        }
        for (int i = curIdx; i < n*n; i++) {
            if (checkErrorRowShouldSkip(temp, i, n) ||
                checkRowShouldSkip(temp, i, n) ||
                checkColumShouldSkip(temp, i, n) ||
                checkBiasShouldSkip(temp, i, n)) {
                continue;
            }
            temp.push_back(i);
            backtracking(n, i+1, temp);
            temp.pop_back();
        }
    }
    bool checkErrorRowShouldSkip(vector<int> &temp, int target, int total) {
        if (temp.size() == 0) return false;
        int lastP = temp[temp.size()-1] / total;
        int curP = target / total;
        if (curP != lastP+1) return true;
        return false;
    }
    bool checkRowShouldSkip(vector<int> &temp, int target, int total) {
        if (temp.size() == 0) return false;
        int curP = target / total;
        for (int i = 0; i < temp.size(); i++) {
            if (curP == i) return true;
        }
        return false;
    }
    bool checkColumShouldSkip(vector<int> &temp, int target, int total) {
        for (auto x: temp) {
            if (target % total == x % total) return true;
        }
        return false;
    }
    bool checkBiasShouldSkip(vector<int> &temp, int target, int total) {
        if (temp.size() == 0) return false;
        int curP = target / total;
        int x, y;
        int d;
        for (int i = 0; i < temp.size(); i++) {
            d = curP - i;
            x = temp[i] + (total+1) * d;
            y = temp[i] + (total-1) * d;
            if (target == x || target == y) return true;
        }
        return false;
    }
    
    vector<string> toVectorString(vector<int> cur, int total) {
        vector<string> ret = {};
        for (auto i: cur) {
            ret.push_back(toString(i%total, total));
        }
        return ret;
    }
    
    string toString(int idx, int total) {
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
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> temp = {};
        backtracking(n, 0, temp);
        return ret;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<vector<string>> ret = sol.solveNQueens(4);
    cout << "ok\n";
    return 0;
}
