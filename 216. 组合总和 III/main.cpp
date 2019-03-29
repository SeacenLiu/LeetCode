//
//  main.cpp
//  216. 组合总和 III
//
//  Created by SeacenLiu on 2019/3/29.
//  Copyright © 2019 成. All rights reserved.
//

/**
 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 
 说明：
 
 所有数字都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: k = 3, n = 7
 输出: [[1,2,4]]
 示例 2:
 
 输入: k = 3, n = 9
 输出: [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void f(int i, int cur, vector<int> tmp, int k, int n) {
        if (cur > n || i > 9 || tmp.size() > k) {
            return;
        }
        if (cur == n && tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for (int j = i+1; j <= 9; ++j) {
            tmp.push_back(j);
            f(j, cur+j, tmp, k, n);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n <= 0) return {};
        res = {};
        vector<int> tmp;
        f(0, 0, tmp, k, n);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<vector<int>> res = sol.combinationSum3(3, 7);
    std::cout << "Hello, World!\n";
    vector<vector<int>> res1 = sol.combinationSum3(3, 9);
    std::cout << "Hello, World!\n";
    vector<vector<int>> res2 = sol.combinationSum3(3, 15);
    std::cout << "Hello, World!\n";
    return 0;
}
