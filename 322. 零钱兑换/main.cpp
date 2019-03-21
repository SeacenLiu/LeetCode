//
//  main.cpp
//  322. 零钱兑换
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定不同面额的硬币 coins 和一个总金额 amount。
 
 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 
 示例 1:
 
 输入: coins = [1, 2, 5], amount = 11
 输出: 3
 解释: 11 = 5 + 5 + 1
 示例 2:
 
 输入: coins = [2], amount = 3
 输出: -1
 说明:
 你可以认为每种硬币的数量是无限的。
 */

/**
 - 动态规划
    - vector<int> dp(amount+1);
    - dp[i] = min(dp[i], dp[i - coin]+1);
        - 11 = 10 + 1
        - 10 = 5 + 5
        - 5 = 5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        if (n <= 0) return  -1;
        // dp[i]表示i元的最小组合数
        vector<int> dp(amount+1, -1);
        dp[0] = 0; // 初始化
        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int coin = coins[j];
                // 用 dp[i - coin] 动态推进！！！
                if (i >= coin && dp[i-coin] != -1 && coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin]+1);
                }
            }
            // 不能使用coins组成
            if (dp[i] == INT_MAX) {
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
};

void test(vector<int> coins, int amount) {
    Solution sol = Solution();
    cout << sol.coinChange(coins, amount) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({1, 2, 5}, 11);
    test({1, 2, 5}, 23);
    test({1, 2, 5}, 24);
    test({2}, 3);
    test({186,419,83,408}, 6249);
    return 0;
}
