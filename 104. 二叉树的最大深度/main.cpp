//
//  main.cpp
//  104. 二叉树的最大深度
//
//  Created by SeacenLiu on 2019/3/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树，找出其最大深度。
 
 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 
 说明: 叶子节点是指没有子节点的节点。
 
 示例：
 给定二叉树 [3,9,20,null,null,15,7]，
 
     3
    / \
   9  20
  /  \
 15   7
 返回它的最大深度 3 。
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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (root->left)
            left = maxDepth(root->left);
        if (root->right)
            right = maxDepth(root->right);
        return max(left+1, right+1);
    }
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

void test(vector<int> a) {
    Solution sol = Solution();
    TreeNode* root = TreeCreator().createTree(a);
    cout << sol.maxDepth(root) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
//    test({});
    return 0;
}
