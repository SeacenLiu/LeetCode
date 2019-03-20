//
//  main.cpp
//  264. 丑数 II
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 编写一个程序，找出第 n 个丑数。
 
 丑数就是只包含质因数 2, 3, 5 的正整数。
 
 示例:
 
 输入: n = 10
 输出: 12
 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 说明:
 
 1 是丑数。
 n 不超过1690。
 */

/**
 - 三指针法
 - 必须三个if 用于防止重复！
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n), idx(3,0);
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            int two = ugly[idx[0]] * 2;
            int three = ugly[idx[1]] * 3;
            int five = ugly[idx[2]] * 5;
            int value = min(min(two, three), five);
            if (value == two)
                ++idx[0];
            if (value == three)
                ++idx[1];
            if (value == five)
                ++idx[2];
            ugly[i] = value;
        }
        return ugly.back();
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.nthUglyNumber(10) << endl;
    return 0;
}
