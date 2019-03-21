//
//  main.cpp
//  343. 整数拆分
//
//  Created by SeacenLiu on 2019/3/21.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 
 示例 1:
 
 输入: 2
 输出: 1
 解释: 2 = 1 + 1, 1 × 1 = 1。
 示例 2:
 
 输入: 10
 输出: 36
 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 说明: 你可以假设 n 不小于 2 且不大于 58。
 */

/**
 //- 越接近 -> 乘积越大
 - 动态规划1：dp[i+j] = max(dp[i+j], max(dp[i], i)*max(dp[j],j));
 - 1: 1 = 1
 - 2: 1*1 = 1
 - 3: 1*2 = 2
 - 4: 2*2 = 4
 - 5: 2*3 = 6
 - 6: 3*3 = 9
 - 7: 2*2*3 = 12
 - 8: 2*3*3 = 18
 - ....
 - 都分解成 2，4
    - 4 -> 2 + 2
    - 5 -> 2 + 3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            dp[i] = max(dp[i-2]*2, dp[i-3]*3);
        }
        return dp[n];
    }
};

class Solution1 {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n-i; ++j) {
                dp[i+j] = max(dp[i+j], max(dp[i], i)*max(dp[j],j));
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.integerBreak(2) << endl;
    cout << sol.integerBreak(10) << endl;
    return 0;
}
