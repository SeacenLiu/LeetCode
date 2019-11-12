//
//  main.cpp
//  100. 相同的树
//
//  Created by SeacenLiu on 2019/11/12.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定两个二叉树，编写一个函数来检验它们是否相同。
 
 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 
 示例 1:
 
 输入:       1         1
           / \       / \
          2   3     2   3
 
 [1,2,3],   [1,2,3]
 
 输出: true
 示例 2:
 
 输入:      1          1
           /           \
          2             2
 
       [1,2],     [1,null,2]
 
 输出: false
 示例 3:
 
 输入:        1         1
            / \       / \
           2   1     1   2
 
          [1,2,1],   [1,1,2]
 
 输出: false
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/same-tree
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

/** 递归方法
 时间复杂度: O(N)，其中 N 是树的结点数，因为每个结点都访问一次。
 空间复杂度: 最优情况（完全平衡二叉树）时为 O(log(N))，最坏情况下（完全不平衡二叉树）时为 O(N)，用于维护递归栈。
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p != nullptr && q != nullptr && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
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

void test(vector<int> pa, vector<int> qa) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(pa);
    TreeNode *q = TreeCreator().createTree(qa);
    cout << Solution().isSameTree(p, q) << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,-1,-1,3,-1,-1}, {1,2,-1,-1,3,-1,-1});
    test({1,2,-1,-1,-1}, {1,-1,2,-1,-1});
    test({1,2,-1,-1,1,-1,-1}, {1,1,-1,-1,2,-1,-1});
    std::cout << "Hello, World!\n";
    return 0;
}
