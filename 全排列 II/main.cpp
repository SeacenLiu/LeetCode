//
//  main.cpp
//  全排列 II
//
//  Created by SeacenLiu on 2018/7/29.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 
 示例:
 
 输入: [1,1,2]
 输出:
 [
    [1,1,2],
    [1,2,1],
    [2,1,1]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    void backtracking(vector<int> &nums, vector<int> &cur, int index) {
        if (index == nums.size()) {
            ret.push_back(cur);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if(i == index || !find(nums, index, i, nums[i])) {
                swap(nums[index], nums[i]);
                cur.push_back(nums[index]);
                backtracking(nums, cur, index+1);
                cur.pop_back();
                swap(nums[index], nums[i]);
            }
        }
        
    }
    
    //从数组的[start,end）范围内寻找元素target
    bool find(vector<int> &num, int start, int end, int target) {
        for(int i = start; i < end; i++)
            if(num[i] == target)
                return true;
        return false;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return ret;
        vector<int> cur = {};
        backtracking(nums, cur, 0);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1,1};
    Solution sol = Solution();
    vector<vector<int>> ret = sol.permuteUnique(nums);
    printf("complete\n");
    return 0;
}
