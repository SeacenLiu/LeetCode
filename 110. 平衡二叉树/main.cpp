//
//  main.cpp
//  110. 平衡二叉树
//
//  Created by SeacenLiu on 2019/11/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树，判断它是否是高度平衡的二叉树。

 本题中，一棵高度平衡二叉树定义为：

 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

 示例 1:

 给定二叉树 [3,9,20,null,null,15,7]
 {3,9,-1,-1,20,15,-1,-1,7,-1,-1}

     3
    / \
   9  20
     /  \
    15   7
 返回 true 。

 示例 2:

 给定二叉树 [1,2,2,3,3,null,null,4,4]
 {1,2,3,4,-1,-1,4,-1,-1,3,-1,-1,2,-1,-1}

        1
       / \
      2   2
     / \
    3   3
   / \
  4   4
 返回 false 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/balanced-binary-tree
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
private:
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ld = depth(root->left);
        int rd = depth(root->right);
        return max(ld, rd) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int d = abs(depth(root->left) - depth(root->right));
        return (d <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};

void test(vector<int> arr) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(arr);
    cout << Solution().isBalanced(p) << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
    test({1,2,3,4,-1,-1,4,-1,-1,3,-1,-1,2,-1,-1});
    std::cout << "Hello, World!\n";
    return 0;
}
