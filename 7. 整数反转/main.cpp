//
//  main.cpp
//  7. 整数反转
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 
 示例 1:
 
 输入: 123
 输出: 321
 示例 2:
 
 输入: -123
 输出: -321
 示例 3:
 
 输入: 120
 输出: 21
 注意:
 
 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，
 
 如果反转后整数溢出那么就返回 0。
 */

/**
 - 思路一：栈
 - 时间复杂度：O(log(x))，x 中大约有 log10(x) 位数字。
 - 空间复杂度：O(1)。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10; // 取个位数
            x /= 10; // 整体向右移
            // 提前溢出判断
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
            // rev + pop
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.reverse(120) << endl;
    cout << sol.reverse(-123) << endl;
    return 0;
}
