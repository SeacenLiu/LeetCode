//
//  main.cpp
//  括号生成
//
//  Created by SeacenLiu on 2018/8/11.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 
 例如，给出 n = 3，生成结果为：
 
 [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtracking("", n, 0, 0);
        return ret;
    }
private:
    vector<string> ret = {};
    void backtracking(string cur, int n, int left, int right) {
        if (cur.length() == n*2) {
            ret.push_back(cur);
            return;
        }
        if (left < n) {
            cur.push_back('(');
            backtracking(cur, n, left+1, right);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            backtracking(cur, n, left, right+1);
            cur.pop_back();
        }
    }
};


/**
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisDFS(n, n, "");
        return ret;
    }
private:
    vector<string> ret = {};
    void generateParenthesisDFS(int left, int right, string cur) {
        if (left > right) return;
        if (left == 0 && right == 0) ret.push_back(cur);
        else {
            if (left > 0) generateParenthesisDFS(left-1, right, cur+'(');
            if (right > 0) generateParenthesisDFS(left, right-1, cur+')');
        }
    }
};
*/

int main(int argc, const char * argv[]) {
    int n = 3;
    Solution sol = Solution();
    vector<string> ret = sol.generateParenthesis(n);
    for (auto str: ret) {
        cout << str << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
