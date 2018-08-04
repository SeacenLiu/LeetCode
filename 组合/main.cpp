//
//  main.cpp
//  组合
//
//  Created by SeacenLiu on 2018/8/4.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 
 示例:
 
 输入: n = 4, k = 2
 输出:
 [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    void backtracking(vector<int> &temp, int n, int k, int s,int total) {
        if (total == k) {
            ret.push_back(temp);
            return;
        }
        for (int i = s; i <= n; i++) {
            temp.push_back(i);
            backtracking(temp, n, k, i+1, total+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp = {};
        backtracking(temp, n, k, 1, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    int k = 2;
    Solution sol = Solution();
    vector<vector<int>> ret = sol.combine(n, k);
    cout << "ok" << endl;
    return 0;
}
