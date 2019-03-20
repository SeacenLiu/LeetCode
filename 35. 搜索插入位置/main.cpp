//
//  main.cpp
//  35. 搜索插入位置
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 
 你可以假设数组中无重复元素。
 
 示例 1:
 
 输入: [1,3,5,6], 5
 输出: 2
 示例 2:
 
 输入: [1,3,5,6], 2
 输出: 1
 示例 3:
 
 输入: [1,3,5,6], 7
 输出: 4
 示例 4:
 
 输入: [1,3,5,6], 0
 输出: 0
 */

/**
 - 二分查找
 - 找第一个小于等于目标值的位置
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = (int)nums.size()-1, mid = left;
        while (left <= right) {
            mid = left + ((right-left) >> 1);
            if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else { // ==
                if (mid == 0 || nums[mid-1] < nums[mid])
                    return mid;
                else
                    right = mid-1;
            }
        }
        return left;
    }
};

void test(vector<int> nums, int target) {
    Solution sol = Solution();
    cout << sol.searchInsert(nums, target) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({1,3,5,6}, 5); // 2
    test({1,3,5,6}, 2); // 1
    test({1,3,5,6}, 7); // 4
    test({1,3,5,6}, 0); // 0
    return 0;
}
