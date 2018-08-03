//
//  main.cpp
//  组合总和 II
//
//  Created by SeacenLiu on 2018/8/3.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 
 candidates 中的每个数字在每个组合中只能使用一次。
 
 说明：
 
 所有数字（包括目标数）都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 所求解集为:
 [
    [1, 7],
    [1, 2, 5],
    [2, 6],
    [1, 1, 6]
 ]
 示例 2:
 
 输入: candidates = [2,5,2,1,2], target = 5,
 所求解集为:
 [
    [1,2,2],
    [5]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    void backtracking(vector<int> &temp, vector<int>& candidates, int target, int index) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            backtracking(temp, candidates, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp = {};
        backtracking(temp, candidates, target, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> candidates = {1,1,1,1,1,1,5}; //{2, 5, 2, 1, 2};
    int target = 5;
    Solution sol = Solution();
    vector<vector<int>> ret = sol.combinationSum2(candidates, target);
    cout << "ok" << endl;
    return 0;
}
