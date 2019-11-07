//
//  main.cpp
//  58. 最后一个单词的长度
//
//  Created by SeacenLiu on 2019/11/7.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 
 如果不存在最后一个单词，请返回 0 。
 
 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 
 示例:
 
 输入: "Hello World"
 输出: 5
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, cnt = 0;
        for (i = (int)s.length()-1; i >= 0; --i) {
            if (s[i] != ' ') {
                break;
            }
        }
        for (; i >= 0; --i) {
            if (s[i] == ' ') {
                break;
            } else {
                ++cnt;
            }
        }
        return cnt;
    }
};

class Solution1 {
public:
    int lengthOfLastWord(string s) {
        int pre = 0, cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                pre = cnt == 0 ? pre : cnt;
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        return cnt == 0 ? pre : cnt;
    }
};

void test(string s) {
    cout << "===========================" << endl;
    cout << s << endl;
    cout << Solution().lengthOfLastWord(s) << endl;
    cout << "===========================" << endl;
}

int main(int argc, const char * argv[]) {
    test("Hello world");
    test("Hello world   ");
    test("world   ");
    test(" world   ");
    std::cout << "Hello, World!\n";
    return 0;
}
