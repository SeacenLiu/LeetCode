//
//  main.cpp
//  279. 完全平方数
//
//  Created by SeacenLiu on 2019/3/21.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 
 示例 1:
 
 输入: n = 12
 输出: 3
 解释: 12 = 4 + 4 + 4.
 示例 2:
 
 输入: n = 13
 输出: 2
 解释: 13 = 4 + 9.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
    return 0;
}
