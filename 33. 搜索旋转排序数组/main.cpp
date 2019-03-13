//
//  main.cpp
//  33. 搜索旋转排序数组
//
//  Created by SeacenLiu on 2019/3/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 
 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 
 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 
 你可以假设数组中不存在重复的元素。
 
 你的算法时间复杂度必须是 O(log n) 级别。
 
 示例 1:
 
 输入: nums = [4,5,6,7,0,1,2], target = 0
 输出: 4
 示例 2:
 
 输入: nums = [4,5,6,7,0,1,2], target = 3
 输出: -1
 */

/**
 二分查找变体问题
 - 规避转折点
 - 找出升序的部分，进行精准移动
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = (int)nums.size()-1, mid = left;
        while (left <= right) {
            mid = left + ((right-left) >> 1);
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[left]) { // 左边是升序的
                if (nums[left] <= target && target < nums[mid]) // 确定在左边
                    right = mid - 1;
                else
                    left = mid + 1;
            } else { // 左边不是升序的
                // 因此右边一定是升序的
                if (nums[mid] < target && target <= nums[right]) // 确定在右边
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

void test(vector<int> nums, int target) {
    cout << "-----------------" << endl;
    for (auto v: nums) cout << v << " ";
    cout << endl;
    cout << target << endl;
    Solution sol = Solution();
    cout << ":" << sol.search(nums, target) << endl;
    cout << "-----------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({4,5,6,7,0,1,2}, 0);
    test({4,5,6,7,0,1,2}, 3);
    test({3,1}, 4);
    return 0;
}
