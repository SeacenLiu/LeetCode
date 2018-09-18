//
//  main.cpp
//  正则表达式匹配
//
//  Created by SeacenLiu on 2018/9/18.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 
 '.' 匹配任意单个字符。
 '*' 匹配零个或多个前面的元素。
 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 
 说明:
 
 s 可能为空，且只包含从 a-z 的小写字母。
 p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 示例 1:
 
 输入:
 s = "aa"
 p = "a"
 输出: false
 解释: "a" 无法匹配 "aa" 整个字符串。
 示例 2:
 
 输入:
 s = "aa"
 p = "a*"
 输出: true
 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
 示例 3:
 
 输入:
 s = "ab"
 p = ".*"
 输出: true
 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 示例 4:
 
 输入:
 s = "aab"
 p = "c*a*b"
 输出: true
 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 示例 5:
 
 输入:
 s = "mississippi"
 p = "mis*is*p*."
 输出: false
 */

#include <iostream>

bool matchCore(char* s, char* p) {
    if(*s == '\0' && *p == '\0')
        return true;
    
    if(*s != '\0' && *p == '\0')
        return false;
    
    if(*(p+1) == '*')
    {
        if(*p == *s || (*p == '.' && *s != '\0'))
            return matchCore(s+1, p+2) || matchCore(s+1, p) || matchCore(s, p+2);
        else
            return matchCore(s, p+2);
    }
    
    if(*s == *p || (*p == '.' && *s != '\0'))
        return matchCore(s+1, p+1);
    
    return false;
}

bool isMatch(char* s, char* p) {
    if(s == nullptr || p == nullptr)
        return false;
    
    return matchCore(s, p);
}


int main(int argc, const char * argv[]) {
    char s[] = "aa";
    char p[] = "a";
    std::cout << isMatch(s, p) << std::endl;;
    std::cout << "Hello, World!\n";
    return 0;
}
