//
//  main.cpp
//  5017. 从根到叶的二进制数之和
//
//  Created by SeacenLiu on 2019/4/7.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 
 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 
 以 10^9 + 7 为模，返回这些数字之和。
 
 示例：
 [](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/04/05/sum-of-root-to-leaf-binary-numbers.png)
 
 输入：[1,0,1,0,1,0,1]
 输出：22
 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 
 提示：
 
 树中的结点数介于 1 和 1000 之间。
 node.val 为 0 或 1 。
 */

/**
 - 要用long
 - 溢出问题
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    long res = 0;
    int mod = 1000000007;
    void f(TreeNode *root, int sum) {
        if (root->left != nullptr)
            f(root->left, (sum*2 + root->val)%mod);
        if (root->right != nullptr)
            f(root->right, (sum*2 + root->val)%mod);
        if (root->left == nullptr && root->right == nullptr)
            res = (res + sum*2 + root->val) % mod;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        res = 0;
        f(root, 0);
        return (int)res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    cout << (10^9 + 7) << endl;
    return 0;
}
