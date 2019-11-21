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

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
    }
};

void test(vector<int> nums) {
    cout << "========================" << endl;
    for (auto val: nums)
        cout << val << " ";
    cout << endl;
    Solution().nextPermutation(nums);
    for (auto val: nums)
        cout << val << " ";
    cout << endl;
    cout << "========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,3});
    test({3,2,1});
    test({1,1,5});
    std::cout << "Hello, World!\n";
    return 0;
}
