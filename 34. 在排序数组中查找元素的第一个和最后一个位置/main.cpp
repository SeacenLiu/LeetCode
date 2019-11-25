//
//  main.cpp
//  34. 在排序数组中查找元素的第一个和最后一个位置
//
//  Created by SeacenLiu on 2019/11/24.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

 你的算法时间复杂度必须是 O(log n) 级别。

 如果数组中不存在目标值，返回 [-1, -1]。

 示例 1:

 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:

 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int core_index(vector<int> nums, int target, bool isLeft) {
        int left = 0, right = (int)nums.size(), mid = 0;
        while (left < right) {
            mid = (left + right) >> 1;
            if (nums[mid] > target || (isLeft && target == nums[mid])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int leftIdx = core_index(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return res;
        }
        
        res[0] = leftIdx;
        res[1] = core_index(nums, target, false) - 1;
        
        return res;
    }
};

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = (int)nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if (mid == 0 || nums[mid-1] < target) {
                    res[0] = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            }
        }
        left = 0;
        right = (int)nums.size() - 1;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (mid == nums.size()-1 || nums[mid+1] > target) {
                    res[1] = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};

void test(vector<int> nums, int target) {
    cout << "=======================" << endl;
    for (auto val: nums)
        cout << val << " ";
    cout << endl;
    vector<int> res = Solution().searchRange(nums, target);
    for (auto val: res)
        cout << val << " ";
    cout << endl;
    cout << "=======================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1}, 1);
    test({1,1}, 1);
    test({}, 8);
    test({5,7,7,8,8,10}, 8);
    test({5,7,7,8,8,10}, 6);
    std::cout << "Hello, World!\n";
    return 0;
}


