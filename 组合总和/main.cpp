//
//  main.cpp
//  组合总和
//
//  Created by SeacenLiu on 2018/8/3.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 
 candidates 中的数字可以无限制重复被选取。
 
 说明：
 
 所有数字（包括 target）都是正整数。
 解集不能包含重复的组合。
 示例 1:
 
 输入: candidates = [2,3,6,7], target = 7,
 所求解集为:
 [
    [7],
    [2,2,3]
 ]
 示例 2:
 
 输入: candidates = [2,3,5], target = 8,
 所求解集为:
 [
    [2,2,2,2],
    [2,3,3],
    [3,5]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    void backtracking(vector<int> &temp, int target, vector<int> &candidates, int startIdx) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++) {
            if (target <= 0) { continue; }
            temp.push_back(candidates[i]);
            backtracking(temp, target-candidates[i], candidates, i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp = {};
        backtracking(temp, target, candidates, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> candidates = {2, 3, 6, 7}; //{2, 3, 5};
    int target = 7; //8;
    Solution sol = Solution();
    vector<vector<int>> ret = sol.combinationSum(candidates, target);
    cout << "ok" << endl;
    return 0;
}
