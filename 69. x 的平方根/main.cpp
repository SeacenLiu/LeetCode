//
//  main.cpp
//  69. x 的平方根
//
//  Created by SeacenLiu on 2019/11/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 实现 int sqrt(int x) 函数。

 计算并返回 x 的平方根，其中 x 是非负整数。

 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

 示例 1:

 输入: 4
 输出: 2
 示例 2:

 输入: 8
 输出: 2
 说明: 8 的平方根是 2.82842...,
      由于返回类型是整数，小数部分将被舍去。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sqrtx
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x/2+1, mid = 0, tmp;
        while (left <= right) {
            mid = (left + right) >> 1;
            tmp = mid * mid;
            if (tmp == x) {
                return (int)mid;
            } else if (tmp < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (int)right;
    }
};

void test(int x) {
    cout << "====================" << endl;
    cout << x << "   " << Solution().mySqrt(x) << endl;
    cout << "====================" << endl;
}

int main(int argc, const char * argv[]) {
    test(4);
    test(8);
    std::cout << "Hello, World!\n";
    return 0;
}
