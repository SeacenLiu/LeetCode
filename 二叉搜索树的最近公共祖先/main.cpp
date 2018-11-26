//
//  main.cpp
//  二叉搜索树的最近公共祖先
//
//  Created by SeacenLiu on 2018/11/26.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 
 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 
 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 
       _______6______
      /              \
  ___2__          ___8__
 /      \        /      \
 0      _4       7       9
       /  \
       3   5
 
 示例 1:
 
 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 输出: 6
 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 示例 2:
 
 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 输出: 2
 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 说明:
 
 所有节点的值都是唯一的。
 p、q 为不同节点且均存在于给定的二叉搜索树中。
 */

/*
 * 从根结点开始找
 * 利用二叉搜索树左子树都小，右子树都大
 * 第一次一大一小就是要找的祖先（注意相等情况）
 * 要么在左子树，要么在右子树，要么就是根节点
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        while (root) {
            if (p->val > root->val && q->val > root->val)
                root = root->right;
            else if (p->val < root->val && q->val < root->val)
                root = root->left;
            else
                return root;
        }
        return nullptr;
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

void ShowSolution(Solution *sol, TreeNode *root, int p, int q) {
    TreeNode *t1 = new TreeNode(p);
    TreeNode *t2 = new TreeNode(q);
    TreeNode *res1 = sol->lowestCommonAncestor(root, t1, t2);
    if (res1) {
        cout << "结点为: " << res1->val << endl;
    } else {
        cout << "没有" << endl;
    }
}

int main(int argc, const char * argv[]) {
    TreeCreator *creator = new TreeCreator();
    TreeNode *root = creator->createTree({6,2,0,-1,-1,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1});
    cout << root << endl;
    
    Solution *sol = new Solution();
    
    ShowSolution(sol, root, 2, 8);
    ShowSolution(sol, root, 2, 4);
    
    return 0;
}
