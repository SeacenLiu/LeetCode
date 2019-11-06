//
//  main.cpp
//  96. 不同的二叉搜索树
//
//  Created by SeacenLiu on 2019/11/6.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

 示例:

 输入: 3
 输出: 5
 解释:
 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n+1, 0);
        a[0] = 1; a[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                a[i] += a[j-1] * a[i-j];
            }
        }
        return a[n];
    }
};

void test(int n) {
    cout << "======================" << endl;
    cout << n << " " << Solution().numTrees(n) << endl;
    cout << "======================" << endl;
}

int main(int argc, const char * argv[]) {
    test(3);
    std::cout << "Hello, World!\n";
    return 0;
}
