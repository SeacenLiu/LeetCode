//
//  main.cpp
//  94. 二叉树的中序遍历
//
//  Created by bobo on 2019/11/30.
//  Copyright © 2019年 成. All rights reserved.
//

/**
 给定一个二叉树，返回它的中序 遍历。
 
 示例:
 
 输入: [1,null,2,3]
 1
  \
   2
  /
 3
 // {1, -1, 2, 3, -1, -1, -1}
 
 输出: [1,3,2]
 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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
        if (a.empty())
            return nullptr;
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
    vector<int> res;
    void core(TreeNode* node) {
        if (node == nullptr)
            return;
        core(node->left);
        res.push_back(node->val);
        core(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        core(root);
        return res;
    }
};

void test(vector<int> arr) {
    cout << "====================" << endl;
    TreeNode *node = TreeCreator().createTree(arr);
    vector<int> res = Solution().inorderTraversal(node);
    for (int val: res)
        cout << val << " ";
    cout << endl;
    cout << "====================" << endl;
}

int main(int argc, const char * argv[]) {
    test({});
    test({1,-1,-1});
    test({1, -1, 2, 3, -1, -1, -1});
    std::cout << "Hello, World!\n";
    return 0;
}
