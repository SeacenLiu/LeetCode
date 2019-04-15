//
//  main.cpp
//  91. 解码方法
//
//  Created by SeacenLiu on 2019/4/15.
//  Copyright © 2019 成. All rights reserved.
//

/**
 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 
 示例 1:
 
 输入: "12"
 输出: 2
 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 示例 2:
 
 输入: "226"
 输出: 3
 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 */

/**
 - dp[i] = dp[i-1] + dp[i-2]
 - 即 dp[i+1] = dp[i] + dp[i-1]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() == 1 && s[0] == '0'))
            return 0;
        if (s.size() == 1)
            return 1;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                dp[i+1] += dp[i-1];
            }
        }
        return dp.back();
    }
};

void test(string s) {
    Solution sol = Solution();
    cout << sol.numDecodings(s) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test("0");
    test("12");
    test("226");
    test("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
    return 0;
}
