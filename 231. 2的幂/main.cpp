//
//  main.cpp
//  231. 2的幂
//
//  Created by SeacenLiu on 2019/11/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

 示例 1:

 输入: 1
 输出: true
 解释: 20 = 1
 示例 2:

 输入: 16
 输出: true
 解释: 24 = 16
 示例 3:

 输入: 218
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/power-of-two
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

// 方法二: 位运算规律法
/**
 若 n = 2^x 且 x 为自然数（即 n 为 2 的幂），则一定满足以下条件：
 1. 恒有 n & (n - 1) == 0，这是因为：
    n 二进制最高位为 1，其余所有位为 0；
    n−1 二进制最高位为 0，其余所有位为 1；
 2. 一定满足 n > 0。
 (&: 都是1才是1)
 
 2^x    n     n - 1        n & (n - 1)
 2^0   0001    0000     (0001) & (0000) == 0
 2^1   0010    0001     (0010) & (0001) == 0
 2^2   0100    0011     (0100) & (0011) == 0
 2^3   1000    0111     (1000) & (0111) == 0
 ...    ...    ...      ...
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// 方法一: 除2到1法
class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        while (n % 2 == 0) {
            n /= 2;
            if (n == 1)
                return true;
        }
        return false;
    }
};

void test(int n) {
    cout << "===================" << endl;
    cout << n << " " << (Solution().isPowerOfTwo(n) ? "true" : "false") << endl;
    cout << "===================" << endl;
}

int main(int argc, const char * argv[]) {
    test(0);
    test(1);
    test(16);
    test(218);
    std::cout << "Hello, World!\n";
    return 0;
}
