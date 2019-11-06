//
//  main.cpp
//  38. 报数
//
//  Created by SeacenLiu on 2019/11/6.
//  Copyright © 2019 成. All rights reserved.
//

/**
 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 被读作  "one 1"  ("一个一") , 即 11。
 11 被读作 "two 1s" ("两个一"）, 即 21。
 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 
 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 
 注意：整数顺序将表示为一个字符串。
 
 示例 1:
 
 输入: 1
 输出: "1"
 示例 2:
 
 输入: 4
 输出: "1211"
 */

/**
 1
 11
 21
 1211
 11221
 212211
 12112221
 1112213211
 312211131221
 1311223113112211
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            char pre = str[0];
            int count = 1;
            for (int j = 1; j < str.length(); j++) {
                char c = str[j];
                if (c == pre) {
                    ++count;
                } else {
                    tmp += '0' + count;
                    tmp += pre;
                    pre = c;
                    count = 1;
                }
            }
            tmp += '0' + count;
            tmp += pre;
            str = tmp;
        }
        return str;
    }
};

void test(int n) {
    cout << "===============================" << endl;
    Solution sol = Solution();
    cout << n << endl;
    cout << sol.countAndSay(n) << endl;
    cout << "===============================" << endl;
}

int main(int argc, const char * argv[]) {
    test(1);
    test(4);
    std::cout << "Hello, World!\n";
    return 0;
}
