//
//  main.cpp
//  111. 二叉树的最小深度
//
//  Created by SeacenLiu on 2019/11/14.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树，找出其最小深度。

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

 说明: 叶子节点是指没有子节点的节点。

 示例:

 给定二叉树 [3,9,20,null,null,15,7],
 {3,9,-1,-1,20,15,-1,-1,7,-1,-1}

     3
    / \
   9  20
     /  \
    15   7
 返回它的最小深度  2.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class TreeCreator {
private:
    int index = 0;
    TreeNode *create_tree_core(vector<int> a) {
        if (a[index] != -1) {
            TreeNode *root = new TreeNode(a[index++]);
            root->left = create_tree_core(a);
            root->right = create_tree_core(a);
            return root;
        } else {
            ++index;
            return nullptr;
        }
    }
public:
    TreeNode *createTree(vector<int> a) {
        index = 0;
        return create_tree_core(a);
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        if (root->left == nullptr || root->right == nullptr)
            return ld + rd + 1;
        return min(ld, rd) + 1;
    }
};

void test(vector<int> pa) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(pa);
    cout << Solution().minDepth(p) << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,-1,-1,-1});
    test({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
    std::cout << "Hello, World!\n";
    return 0;
}
