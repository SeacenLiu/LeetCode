//
//  main.cpp
//  125. 验证回文串
//
//  Created by SeacenLiu on 2019/11/16.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

 说明：本题中，我们将空字符串定义为有效的回文串。

 示例 1:

 输入: "A man, a plan, a canal: Panama"
 输出: true
 示例 2:

 输入: "race a car"
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-palindrome
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

class Solution {
private:
    bool isValid(char ch) {
        return (ch - '0' >= 0 && '9' - ch >= 0) ||
               (ch - 'a' >= 0 && 'z' - ch >= 0) ||
               (ch - 'A' >= 0 && 'Z' - ch >= 0);
    }
    char demotion(char ch) {
        if (ch - 'A' >= 0 && 'Z' - ch >= 0) {
            ch = ch - 'A' + 'a';
        }
        return ch;
    }
    bool isEqual(char l, char r) {
        return demotion(l) == demotion(r);
    }
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int i = 0;
        int j = (int)s.length() - 1;
        while (i < j) {
            if (isValid(s[i])) {
                while (!isValid(s[j])) {
                    --j;
                }
                if (!isEqual(s[i], s[j])) {
                    return false;
                }
                --j;
            }
            ++i;
            if (i >= s.length() || j < 0) {
                break;
            }
        }
        return true;
    }
};

void test(string s, bool ans) {
    cout << "==============================" << endl;
    cout << s << endl;
    cout << ans << endl;
    cout << (Solution().isPalindrome(s) ? "ture" : "false") << endl;
    cout << "==============================" << endl;
}

int main(int argc, const char * argv[]) {
    test("A man, a plan, a canal: Panama", true);
    test("race a car", false);
    test("", true);
    test("OP", false);
    test("0P", false);
//    test(nullptr, true);
    std::cout << "Hello, World!\n";
    return 0;
}
