//
//  main.cpp
//  238. 除自身以外数组的乘积
//
//  Created by SeacenLiu on 2019/11/18.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 示例:

 输入: [1,2,3,4]
 输出: [24,12,8,6]
 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

 进阶：
 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/product-of-array-except-self
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

// 使用左边乘积和右边乘积进行计算
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<int> res(nums.size(), 0);
        int k = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = k;
            k *= nums[i];
        }
        k = 1;
        for (int j = (int)nums.size()-1; j >= 0; --j) {
            res[j] *= k;
            k *= nums[j];
        }
        return res;
    }
};

void test(vector<int> nums) {
    cout << "=======================" << endl;
    for (auto val: nums) cout << val << " ";
    cout << endl;
    vector<int> res = Solution().productExceptSelf(nums);
    for (auto val: res) cout << val << " ";
    cout << endl;
    cout << "=======================" << endl;
}

int main(int argc, const char * argv[]) {
    test({});
    test({1});
    test({1,2,3,4});
    std::cout << "Hello, World!\n";
    return 0;
}
