//
//  main.cpp
//  28. 实现 strStr()
//
//  Created by SeacenLiu on 2019/11/5.
//  Copyright © 2019 成. All rights reserved.
//

/**
 实现 strStr() 函数。

 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

 示例 1:

 输入: haystack = "hello", needle = "ll"
 输出: 2
 示例 2:

 输入: haystack = "aaaaa", needle = "bba"
 输出: -1
 说明:

 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty() || haystack.size() < needle.size()) {
            return -1;
        }
        int length = (int)haystack.size();
        if (haystack == needle) {
            return 0;
        }
        for (int i = 0; i < haystack.size(); ++i) {
            if (i <= length - needle.size()) {
                if (haystack.substr(i, needle.size()) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};

void test(string haystack, string needle) {
    cout << "=========================" << endl;
    cout << haystack << "   " << needle << endl;
    Solution sol = Solution();
    int res = sol.strStr(haystack, needle);
    cout << res << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test("hello", "ll");
    test("aaaaa", "bba");
    std::cout << "Hello, World!\n";
    return 0;
}
