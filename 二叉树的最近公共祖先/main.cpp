//
//  main.cpp
//  二叉树的最近公共祖先
//
//  Created by SeacenLiu on 2018/11/22.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 
 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 
 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 
      _______3______
     /              \
  ___5__          ___1__
 /      \        /      \
 6      _2       0       8
       /  \
       7   4
 // #前: 3, 5, 6, #, #, 2, 7, #, #, 4, #, #, 1, 0, #, #, 8, #, #
 // 前: 3, 5, 6, 2, 7, 4, 1, 0, 8
 // 中: 6, 5, 7, 2, 4, 3, 0, 1, 8
 // 后: 6, 7, 4, 2, 5, 0, 8, 1, 3
 示例 1:
 
 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 输出: 3
 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 示例 2:
 
 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 输出: 5
 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 说明:
 
 所有节点的值都是唯一的。
 p、q 为不同节点且均存在于给定的二叉树中。
 */

/*
 思路：
 1. 获取从根结点到 p 的路径
 2. 获取从根结点到 q 的路径
 3. 获取路径的方式: 前序遍历，压栈，若在结点的儿子中都没找到就弹出，最后到找到就停止递归
 4. 获取两个路径中最后相等的
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
private:
    bool getNodePath(TreeNode *root, TreeNode *aim, vector<TreeNode*> &path) {
        if (root != nullptr)
            path.push_back(root);
        if (root->val == aim->val)
            return true;
        bool found = false;
        if (root->left != nullptr)
            found = getNodePath(root->left, aim, path);
        if (!found && root->right != nullptr)
            found = getNodePath(root->right, aim, path);
        if (!found)
            path.pop_back();
        return found;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 获取 p 的路径
        vector<TreeNode*> pPath;
        if (!getNodePath(root, p, pPath))
            return nullptr;
        // 获取 q 的路径
        vector<TreeNode*> qPath;
        if (!getNodePath(root, q, qPath))
            return nullptr;
        // 查找最后一个相同的
        int len = 0;
        if (pPath.size() > qPath.size())
            len = (int)qPath.size();
        else
            len = (int)pPath.size();
        TreeNode *res = nullptr;
        for (int i = 0; i < len; ++i)
            if (pPath[i] == qPath[i])
                res = pPath[i];
        return res;
    }
};

// 前: 3, 5, 6, #, #, 2, 7, #, #, 4, #, #, 1, 0, #, #, 8, #, #
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

int main(int argc, const char * argv[]) {
    TreeCreator *creator = new TreeCreator();
    TreeNode *root = creator->createTree({3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1});
    cout << root << endl;
    Solution *sol = new Solution();
    TreeNode *p = new TreeNode(5);
    TreeNode *q = new TreeNode(1);
    cout << sol -> lowestCommonAncestor(root, p, q)->val << endl;
    
    p = new TreeNode(5);
    q = new TreeNode(4);
    cout << sol -> lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}
