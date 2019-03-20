//
//  main.cpp
//  263. 丑数
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 编写一个程序判断给定的数是否为丑数。
 
 丑数就是只包含质因数 2, 3, 5 的正整数。
 
 示例 1:
 
 输入: 6
 输出: true
 解释: 6 = 2 × 3
 示例 2:
 
 输入: 8
 输出: true
 解释: 8 = 2 × 2 × 2
 示例 3:
 
 输入: 14
 输出: false
 解释: 14 不是丑数，因为它包含了另外一个质因数 7。
 说明：
 
 1 是丑数。
 输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
 */

/**
 - 一直除 2，3，5，知道 num 为 1 即是丑数
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return false;
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.isUgly(6) << endl;
    cout << sol.isUgly(8) << endl;
    cout << sol.isUgly(14) << endl;
    return 0;
}
