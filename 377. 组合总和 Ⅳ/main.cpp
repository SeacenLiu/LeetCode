//
//  main.cpp
//  377. 组合总和 Ⅳ
//
//  Created by SeacenLiu on 2019/4/12.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
 
 示例:
 nums = [1, 2, 3]
 target = 4
 
 所有可能的组合为：
 (1, 1, 1, 1)
 (1, 1, 2)
 (1, 2, 1)
 (1, 3)
 (2, 1, 1)
 (2, 2)
 (3, 1)
 
 请注意，顺序不同的序列被视作不同的组合。
 
 因此输出为 7。
 进阶：
 如果给定的数组中含有负数会怎么样？
 问题会产生什么变化？
 我们需要在题目中添加什么限制来允许负数的出现？
 */

/**
 - 回溯法(最笨)
    - 超时
 - 递归方式
    - target = i + target-i
    - 超时
 - 回溯 + 备忘录 （推荐）
 - 动态规划
    - dp[i] 代表组合数为i时使用nums中的数能组成的组合数的个数
    - target = i + target-i
    - dp[target] = dp[target] + dp[target-i]
    - 从底部开始构建，dp[0]=1
    - 有溢出问题
    - e.g.
        - dp[i]=dp[i-nums[0]]+dp[i-nums[1]]+dp[i=nums[2]]+...
        - 举个例子比如nums=[1,3,4],target=7;
        - dp[7]=dp[6]+dp[4]+dp[3]
        - 其实就是说7的组合数可以由三部分组成，1和dp[6]，3和dp[4],4和dp[3];
 
 */

#include <iostream>
#include <vector>
using namespace std;

// 动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if (i >= nums[j])
                    dp[i] += dp[i-nums[j]];
                else
                    break;
            }
        }
        return (int)dp[target];
    }
};

// 回溯 + 备忘录
class Solution3 {
private:
    vector<int> memo;
    int search(vector<int> nums, int target) {
        if (memo[target] != -1) {
            return memo[target];
        }
        int res = 0;
        for (int num : nums) {
            if (target >= num) {
                res += search(nums, target - num);
            }
        }
        memo[target] = res;
        return res;
    }
public:
    int combinationSum4(vector<int> nums, int target) {
        memo = vector<int>(target + 1, -1);
        memo[0] = 1;
        return search(nums, target);
    }
};

// 递归方式
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if (target == 0) {
            return 1;
        }
        int res = 0;
        for (int num : nums) {
            if (target >= num) {
                res += combinationSum4(nums, target - num);
            }
        }
        return res;
    }
};

// 回溯法
class Solution1 {
private:
    int res = 0;
    void f(int idx, int cur, vector<int> nums, int target) {
        if (cur == target) {
            res += 1;
            return;
        }
        if (cur > target)
            return;
        for (int i = 0; i < nums.size(); ++i) {
            f(i, cur+nums[i], nums, target);
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        f(0, 0, nums, target);
        return res;
    }
};

void test(vector<int> nums, int target) {
    Solution sol = Solution();
    cout << sol.combinationSum4(nums, target) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({2,1,3}, 4);
    test({3,33,333}, 10000);
    return 0;
}
