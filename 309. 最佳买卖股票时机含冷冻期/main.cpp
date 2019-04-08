//
//  main.cpp
//  309. 最佳买卖股票时机含冷冻期
//
//  Created by SeacenLiu on 2019/4/8.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
 
 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 
 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 示例:
 
 输入: [1,2,3,0,2]
 输出: 3
 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 */

/**
 - 多了一个冷冻期
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1)
            return 0;
        vector<int> dp(prices.size()+1,0);
        for(int i=2; i<=prices.size(); ++i) { // 卖出时机
            dp[i] = dp[i-1];
            for(int j=i-1; j>0; --j) { // 买入时机
                if(prices[i-1] > prices[j-1]) {
                    int temp = (j-2>0) ? dp[j-2] : 0; // 冷冻期之前的收入
                    dp[i] = max(dp[i], temp+prices[i-1]-prices[j-1]);
                }
            }
        }
        return dp[prices.size()];
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    vector<int> a = {1,2,3,0,2};
    cout << sol.maxProfit(a) << endl;
    return 0;
}
