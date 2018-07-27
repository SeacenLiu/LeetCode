//
//  main.cpp
//  回文数
//
//  Created by SeacenLiu on 2018/7/25.
//  Copyright © 2018年 成. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 
 输入: 121
 输出: true
 
 输入: -121
 输出: false
 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 
 输入: 10
 输出: false
 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 
 进阶:
 
 你能不将整数转为字符串来解决这个问题吗？
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    cout << sol.isPalindrome(121) << endl;
    cout << sol.isPalindrome(1212) << endl;
    cout << sol.isPalindrome(-121) << endl;
    return 0;
}
