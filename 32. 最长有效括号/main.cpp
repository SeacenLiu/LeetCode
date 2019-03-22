//
//  main.cpp
//  32. 最长有效括号
//
//  Created by SeacenLiu on 2019/3/22.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 
 示例 1:
 
 输入: "(()"
 输出: 2
 解释: 最长有效括号子串为 "()"
 示例 2:
 
 输入: ")()())"
 输出: 4
 解释: 最长有效括号子串为 "()()"
 */

/**
 - 匹配方式: 栈 -> '('入栈  ')'出栈
 - 思路一:
    - 栈中保存'('出现的位置
 - 思路二: 动态规划
    - 逆向遍历
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 参考用
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int maxMatch = 0;
        int len = (int)s.length();
        vector<int> dp(len, 0);
        for(int i = len-2; i >= 0; --i){
            int symIndex = i+1+dp[i+1];
            if('(' == s[i] && symIndex < len && ')' == s[symIndex]){
                dp[i] = dp[i+1]+2;
                if(symIndex+1 < len){
                    dp[i] += dp[symIndex+1];
                }
            }
            maxMatch = max(maxMatch, dp[i]);
        }
        return maxMatch;
    }
};

class Solution1 {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int maxMatch = 0;
        int start = 0;
        stack<int> stack;
        for (int index = 0; index < s.length(); ++index) {
            if (s[index] == '(') {
                // 入栈
                stack.push(index);
            } else {
                // 检查出栈
                if (stack.empty()) {
                    start = index + 1;
                } else {
                    stack.pop();
                    if (stack.empty()) {
                        maxMatch = max(maxMatch, index-start+1);
                    } else {
                        maxMatch = max(maxMatch, index-stack.top());
                    }
                }
            }
        }
        return maxMatch;
    }
};

void test(string s, int ans) {
    cout << "---------------" << endl;
    cout << s << endl;
    Solution sol = Solution();
    cout << ans << endl;
    cout << sol.longestValidParentheses(s) << endl;
    cout << "---------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test("(()", 2);
    test(")()())", 4);
    test("()(()", 2);
    return 0;
}
