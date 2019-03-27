//
//  main.cpp
//  79. 单词搜索
//
//  Created by SeacenLiu on 2019/3/25.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 
 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 
 示例:
 
 board =
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 
 给定 word = "ABCCED", 返回 true.
 给定 word = "SEE", 返回 true.
 给定 word = "ABCB", 返回 false.
 */

/**
 - 回溯法
 - 注意剪枝问题
    - 访问情况数组
    - 判断是否匹配，不要一错再错
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool f(int i, int j, int curIdx, string curStr, vector<vector<bool>>& visited, vector<vector<char>>& board, string word) {
        if (curStr == word) {
            return true;
        }
        // 越界
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        // 不符合
        if (board[i][j] != word[curIdx])
            return false;
        // 已访问
        if (visited[i][j])
            return false;
        visited[i][j] = true;
        curStr += board[i][j];
        if (f(i-1, j, curIdx+1, curStr, visited, board, word) ||
            f(i+1, j, curIdx+1, curStr, visited, board, word) ||
            f(i, j-1, curIdx+1, curStr, visited, board, word) ||
            f(i, j+1, curIdx+1, curStr, visited, board, word)) {
            return true;
        }
        // 回溯
        visited[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                string tmpStr;
                if (f(i, j, 0, tmpStr, visited, board, word))
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<char> b1 = {'A','B','C','E'};
    vector<char> b2 = {'S','F','C','S'};
    vector<char> b3 = {'A','D','E','E'};
    vector<vector<char>> board = {b1, b2, b3};
    Solution sol = Solution();
    cout << sol.exist(board, "ABCCED") << endl; // true
    cout << sol.exist(board, "SEE") << endl; // true
    cout << sol.exist(board, "ABCB") << endl; // false
    return 0;
}
