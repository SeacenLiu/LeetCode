//
//  main.cpp
//  全排列
//
//  Created by SeacenLiu on 2018/7/31.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个没有重复数字的序列，返回其所有可能的全排列。
 
 示例:
 
 输入: [1,2,3]
 输出:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    void backtracking(vector<int> &nums, vector<int> &cur, int index) {
        vector<int> n = nums;
        vector<int> c = cur;
        if (index == nums.size()) {
            ret.push_back(cur);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            cur.push_back(nums[index]);
            backtracking(nums, cur, index+1);
            cur.pop_back();
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ret;
        vector<int> cur = {};
        backtracking(nums, cur, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    Solution sol = Solution();
    vector<vector<int>> ret = sol.permute(nums);
    printf("complete\n");
    return 0;
}
