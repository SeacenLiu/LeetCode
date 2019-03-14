//
//  main.cpp
//  230. 二叉搜索树中第K小的元素
//
//  Created by SeacenLiu on 2019/3/14.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 
 说明：
 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 
 示例 1:
 
 输入: root = [3,1,4,null,2], k = 1
    3
   / \
  1   4
   \
    2
 输出: 1
 
 示例 2:
 
 输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
 输出: 3
 
 进阶：
 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 */

/**
 - 思路一: 中序遍历 + 计数
 - 思路二: 子树高度计算
    - 左边都是小于root的
    - 如果左子树的高度刚好为k-1，那么 root 就是答案
    - 如果左子树的高度大于等于k，说明答案在左子树，就左移一个继续递归
    - 如果左子树的高度小于k，说明答案在右子树，就右移一个继续找第 k-leftHeight-1 个
 - 思路三: 非递归 + 中序遍历
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
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        vector<TreeNode*> stack;
        TreeNode* p = root;
        while (k > 0 && (!stack.empty() || p)) {
            if (p) {
                stack.push_back(p);
                p = p->left;
            } else {
                p = stack.back();
                stack.pop_back();
                if (--k == 0) return p->val;
                p = p->right;
            }
        }
        return -1;
    }
};

class Solution2 {
private:
    int treeHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + treeHeight(root->left) + treeHeight(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        int leftHeight = treeHeight(root->left);
        if (k == leftHeight+1) {
            return root->val;
        } else if (leftHeight >= k) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k-leftHeight-1);
        }
    }
};

class Solution1 {
private:
    int res = -1;
    void infixOrder(TreeNode* root, int& k) {
        if (root == nullptr) return;
        if (root->left)
            infixOrder(root->left, k);
        if (--k == 0)
            res = root->val;
        if (root->right)
            infixOrder(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        infixOrder(root, k);
        return res;
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
        if (a.empty()) return nullptr;
        index = 0;
        return create_tree_core(a);
    }
};

void test(vector<int> a, int k) {
    TreeNode *root = TreeCreator().createTree(a);
    Solution sol = Solution();
    cout << sol.kthSmallest(root, k) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({}, 1);
    test({3,1,-1,2,-1,-1,4,-1,-1}, 1);
    test({5,3,2,1,-1,-1,-1,4,-1,-1,6,-1,-1}, 3);
    test({10,6,4,-1,-1,8,7,-1,-1,-1,12,11,-1,-1,-1}, 3);
    return 0;
}

/** 非递归中序遍历
void infixOrder(TreeNode* root) {
    if (root == nullptr) return;
    vector<TreeNode*> stack;
    TreeNode* p = root;
    while (!stack.empty() || p) {
        if (p) {
            stack.push_back(p);
            p = p->left;
        } else {
            p = stack.back();
            stack.pop_back();
            cout << p->val << endl;
            p = p->right;
        }
    }
}
*/
