//
//  main.cpp
//  有效的括号
//
//  Created by SeacenLiu on 2018/10/26.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 
 示例 1:
 
 输入: "()"
 输出: true
 示例 2:
 
 输入: "()[]{}"
 输出: true
 示例 3:
 
 输入: "(]"
 输出: false
 示例 4:
 
 输入: "([)]"
 输出: false
 示例 5:
 
 输入: "{[]}"
 输出: true
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> data;
        for (char ch: s) {
            if (ch == '(' || ch == '[' || ch == '{')
                data.push_back(ch);
            else if (data.empty())
                return false;
            else {
                char top = data[data.end()-data.begin()-1];
                if ((top == '(' && ch == ')')
                    || (top == '[' && ch == ']')
                    || (top == '{' && ch == '}'))
                    data.pop_back();
                else
                    return false;
            }
        }
        return data.empty();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol = Solution();
    printf("%d %d \n", '(', ')');
    printf("%d %d \n", '[', ']');
    printf("%d %d \n", '{', '}');
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(]") << endl;
    cout << sol.isValid("([)]") << endl;
    cout << sol.isValid("{[]}") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
