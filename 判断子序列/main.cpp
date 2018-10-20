//
//  main.cpp
//  判断子序列
//
//  Created by SeacenLiu on 2018/10/20.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 
 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 
 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 
 示例 1:
 s = "abc", t = "ahbgdc"
 
 返回 true.
 
 示例 2:
 s = "axc", t = "ahbgdc"
 
 返回 false.
 
 后续挑战 :
 
 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        char* sc = &s[0];
        for (char* tc = &t[0]; *tc != '\0'; tc++) {
            if (*sc == *tc)
                sc++;
            if (*sc == '\0')
                return true;
        }
        return false;
    }
};

/** 没有经过大数处理的
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        int sOffSet = 0;
        int sSize = (int)s.size();
        for (auto c: t) {
            if (s[sOffSet] == c) {
                sOffSet++;
            }
            if (sOffSet == sSize)
                return true;
        }
        return false;
    }
};
*/
 
int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    cout << sol.isSubsequence("abc", "ahbgdc") << endl;
    cout << sol.isSubsequence("axc", "ahbgdc") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
