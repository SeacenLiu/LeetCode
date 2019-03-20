//
//  main.cpp
//  152. 乘积最大子序列
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 
 示例 1:
 
 输入: [2,3,-2,4]
 输出: 6
 解释: 子数组 [2,3] 有最大乘积 6。
 示例 2:
 
 输入: [-2,0,-1]
 输出: 0
 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 */

/**
 - 暴力法
 - 动态规划
    - 每一步只需要记住其前一步的 整数最大值 和 负数的最小值
 - 正常做法
    - 保存最大值
    - 保存最小值
    - 负负得正，因此需要进行交换
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int res = nums[0], maxN = nums[0], minN = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) // 如果数组是负的，交换两数
                swap(maxN, minN);
            maxN = max(maxN*nums[i], nums[i]);
            minN = min(minN*nums[i], nums[i]);
            res = max(res, maxN);
        }
        return res;
    }
};

void test(vector<int> nums, int ans) {
    cout << "----------------" << endl;
    for (auto v: nums) cout << v << " ";
    cout << endl;
    Solution sol = Solution();
    cout << ans << endl;
    cout << sol.maxProduct(nums) << endl;
    cout << "----------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({2,3,-2,4},6);
    test({-2,0,-1},0);
    test({-2,4,2,3},24);
    test({-2,4,-2,-3},24);
    return 0;
}
