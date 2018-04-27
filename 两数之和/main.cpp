//
//  main.cpp
//  两数之和
//
//  Created by SeacenLiu on 2018/4/27.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 
 示例:
 给定 nums = [2, 7, 11, 15], target = 9
 
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    goto here;
                }
            }
        }
    here:
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(11);
    a.push_back(15);
    Solution solution = Solution();
    vector<int> ret = solution.twoSum(a, 9);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    return 0;
}

