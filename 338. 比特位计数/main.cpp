//
//  main.cpp
//  338. 比特位计数
//
//  Created by SeacenLiu on 2019/3/21.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 
 示例 1:
 
 输入: 2
 输出: [0,1,1]
 示例 2:
 
 输入: 5
 输出: [0,1,1,2,1,2]
 进阶:
 
 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 要求算法的空间复杂度为O(n)。
 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 */

/**
 0: 0 -> 0
 1: 1 -> 1
 2: 10 -> 1
 3: 11 -> 2
 4: 100 -> 1
 5: 101 -> 2
 6: 110 -> 2
 7: 111 -> 3
 */

/**
 - & 运算：都是1才是1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res(num+1, 0);
        // 初始值
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            // 动态推进
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};

void test(int num) {
    cout << "-----------------" << endl;
    cout << num << endl;
    Solution sol = Solution();
    vector<int> res = sol.countBits(num);
    for (auto v: res) cout << v << " ";
    cout << endl;
    cout << "-----------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test(2);
    test(5);
    return 0;
}
