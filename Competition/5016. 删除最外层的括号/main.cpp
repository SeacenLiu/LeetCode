//
//  main.cpp
//  5016. 删除最外层的括号
//
//  Created by SeacenLiu on 2019/4/7.
//  Copyright © 2019 成. All rights reserved.
//

/**
 有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
 
 如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
 
 给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
 
 对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。
 
 
 
 示例 1：
 
 输入："(()())(())"
 输出："()()()"
 解释：
 输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
 删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
 示例 2：
 
 输入："(()())(())(()(()))"
 输出："()()()()(())"
 解释：
 输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
 删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
 示例 3：
 
 输入："()()"
 输出：""
 解释：
 输入字符串为 "()()"，原语化分解得到 "()" + "()"，
 删除每个部分中的最外层括号后得到 "" + "" = ""。
 
 
 提示：
 
 S.length <= 10000
 S[i] 为 "(" 或 ")"
 S 是一个有效括号字符串
 */

#include <iostream>
#include "vector"
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<int> stack;
        vector<int> ignore(S.length(), 0);
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                stack.push_back(i);
            } else {
                int leftIdx = stack.front();
                stack.pop_back();
                if (stack.empty()) {
                    // 这对没用
                    ignore[leftIdx] = 1;
                    ignore[i] = 1;
                }
            }
        }
        string res;
        for (int i = 0; i < S.length(); ++i) {
            if (ignore[i] != 1) {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.removeOuterParentheses("(()())(())") << endl; // "()()()"
    cout << sol.removeOuterParentheses("(()())(())(()(()))") << endl; // "()()()()(())"
    cout << sol.removeOuterParentheses("()()") << endl; // ""
    return 0;
}
