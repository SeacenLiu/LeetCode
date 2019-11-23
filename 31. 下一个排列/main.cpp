//
//  main.cpp
//  31. 下一个排列
//
//  Created by SeacenLiu on 2019/11/21.
//  Copyright © 2019 成. All rights reserved.
//

/**
 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 
 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 
 必须原地修改，只允许使用额外常数空间。
 
 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/next-permutation
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 官方解题：
 https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode/
 */
class Solution {
private:
    void reverse(vector<int> &nums, int start) {
        int i = start, j = (int)nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = (int)nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
};

void test(vector<int> nums, vector<int> ans) {
    cout << "========================" << endl;
    for (auto val: nums)
        cout << val << " ";
    cout << endl;
    for (auto val: ans)
        cout << val << " ";
    cout << endl;
    Solution().nextPermutation(nums);
    for (auto val: nums)
        cout << val << " ";
    cout << endl;
    cout << "========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,3}, {1,3,2});
    test({3,2,1}, {1,2,3});
    test({1,1,5}, {1,5,1});
    std::cout << "Hello, World!\n";
    return 0;
}
