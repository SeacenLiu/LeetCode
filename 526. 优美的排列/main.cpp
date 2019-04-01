//
//  main.cpp
//  526. 优美的排列
//
//  Created by SeacenLiu on 2019/3/31.
//  Copyright © 2019 成. All rights reserved.
//

/**
 假设有从 1 到 N 的 N 个整数，
 如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，
 我们就称这个数组为一个优美的排列。条件：
 
 1. 第 i 位的数字能被 i 整除
 2. i 能被第 i 位上的数字整除
 现在给定一个整数 N，请问可以构造多少个优美的排列？
 
 示例1:
 
 输入: 2
 输出: 2
 解释:
 
 第 1 个优美的排列是 [1, 2]:
 第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
 第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
 
 第 2 个优美的排列是 [2, 1]:
 第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
 第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
 说明:
 
 N 是一个正整数，并且不会超过15。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int res = 0;
    void f(int idx, vector<int>& cur, vector<int>& nums) {
        if (idx == nums.size()) {
                res += 1;
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            swap(nums[idx], nums[i]);
            cur.push_back(nums[idx]);
            if ((cur[idx] % (idx+1) == 0) || ((idx+1) % cur[idx] == 0))
                f(idx+1, cur, nums);
            cur.pop_back();
            swap(nums[idx], nums[i]);
        }
    }
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i)
            nums[i] = i+1;
        vector<int> cur;
        f(0, cur, nums);
        return res;
    }
};

void test(int N) {
    cout << "-----------------------" << endl;
    Solution sol  = Solution();
    cout << N << endl;
    cout << sol.countArrangement(N) << endl;
    cout << "-----------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test(2);
    return 0;
}

/**
 for (auto v: a) {
 cout << v << " ";
 }
 cout << endl;
 */
