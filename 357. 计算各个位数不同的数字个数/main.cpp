//
//  main.cpp
//  357. 计算各个位数不同的数字个数
//
//  Created by SeacenLiu on 2019/4/3.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 
 示例:
 
 输入: 2
 输出: 91
 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 */

/**
 - 0
 - 1
 - 10
 - 100
 - 1000
 - 10000
 - 思路
    - 大于等于10位数的数字一定是不符合的
    - 排列组合(eg.n=8):
        - 100000000
        - 组合数 = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2
        - 递归加上 n = 7的情况
        - 递归下去
 */

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 10;
        }
        else if (n > 10) {
            return countNumbersWithUniqueDigits(10);
        }
        else{
            int tempRes = 9, cnt = 9;
            for (int index = n - 1; index > 0; --index){
                // 排列组合
                tempRes *= cnt--;
            }
            return tempRes + countNumbersWithUniqueDigits(n - 1);
        }
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.countNumbersWithUniqueDigits(2) << endl;
    return 0;
}
