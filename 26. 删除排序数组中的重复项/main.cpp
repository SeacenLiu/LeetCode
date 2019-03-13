//
//  main.cpp
//  26. 删除排序数组中的重复项
//
//  Created by SeacenLiu on 2019/3/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 
 给定数组 nums = [1,1,2],
 
 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 示例 2:
 
 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 
 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 
 你不需要考虑数组中超出新长度后面的元素。
 说明:
 
 为什么返回数值是整数，但输出的答案是数组呢?
 
 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 
 你可以想象内部操作如下:
 
 // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 int len = removeDuplicates(nums);
 
 // 在函数里修改输入数组对于调用者是可见的。
 // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 for (int i = 0; i < len; i++) {
    print(nums[i]);
 }
 */

/**
 i: 顺序的尾部
 j: 准备替换的位置
 k: 试探位
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return n;
        int sum = 1, i = 0, j = 1;
        for (int k = 1; k < n; ++k) {
            if (nums[i] < nums[j]) {
                ++i;
                ++j;
                ++sum;
            } else if (nums[i] == nums[j]) {
                if (nums[k] > nums[j]) {
                    swap(nums[j], nums[k]);
                    ++i;
                    ++j;
                    ++sum;
                }
            } else {
                if (nums[k] > nums[i]) {
                    swap(nums[j], nums[k]);
                    ++i;
                    ++j;
                    ++sum;
                }
            }
        }
        return sum;
    }
};

void test(vector<int> arr) {
    for (auto v: arr) {
        cout << v << " ";
    }
    cout << endl;
    Solution sol = Solution();
    int n = sol.removeDuplicates(arr);
    for (int i=0;i<n;++i) {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({});
    test({1});
    test({1,1});
    test({1,1,2});
    test({0,0,1,1,1,2,2,3,3,4});
    test({0,1,2,3,4});
    return 0;
}
