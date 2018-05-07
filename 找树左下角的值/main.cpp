//
//  main.cpp
//  找树左下角的值
//
//  Created by SeacenLiu on 2018/5/7.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个二叉树，在树的最后一行找到最左边的值。
 
 示例 1:
 输入:
   2
  / \
 1   3
 输出:
 1
 
 示例 2:
 输入:
       1
      / \
     2   3
    /   / \
   4   5   6
  /
 7
 输出:
 7
 
 注意: 您可以假设树（即给定的根节点）不为 NULL。
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

TreeNode *creat(TreeNode *bt) {
    char ch;
    cin >> ch;
    if (ch == '#') bt = NULL;
    else {
        int num = ch - '0';
        bt = new TreeNode(num);
        bt -> left = creat(bt -> left);
        bt -> right = creat(bt -> right);
    }
    return bt;
}

/**
 * 广度遍历 + 先走右孩子 + 最后一个遍历的 = 答案
 */

/**
 * 二叉树的层序遍历思路：
 * 使用队列的特性
 * 先进先出
 * 遍历左右子树
 */

//class Solution {
//private:
//    void preOrder(TreeNode *bt) {
//        if (!bt) return;
//        else {
//            preOrder(bt->left);
//            preOrder(bt->right);
//            cout << bt->val << endl;
//        }
//    }
//
//    int leverOrder(TreeNode *root) {
//        int front, rear;
//        int val = root->val;
//        TreeNode *q[10000];
//        TreeNode *bt;
//        front = rear = 1;
//        if (root == NULL) return val;
//        q[++rear] = root;
//        while (front != rear) {
//            bt = q[++front];
//            val = bt->val;
//            if (bt -> right != NULL)
//                q[++rear] = bt -> right;
//            if (bt -> left != NULL)
//                q[++rear] = bt -> left;
//        }
//        return val;
//    }
//public:
//    int findBottomLeftValue(TreeNode* root) {
//        return leverOrder(root);
//    }
//};

/// LeetCode 上的其他答案
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* res=NULL;
        int max_dep=0;
        find_left(root,1,res,max_dep);
        return res->val;
    }
private:
    void find_left(TreeNode* root,int depth,TreeNode* &res,int& max_dep){
        if(root==NULL){
            return;
        }
        if(depth>max_dep){
            res=root;
            max_dep=depth;
        }
        find_left(root->left,depth+1,res,max_dep);
        find_left(root->right,depth+1,res,max_dep);
    }
};

// 2 1 # # 3 # #
// 1 2 # # 3 4 # # 5 # #
int main(int argc, const char * argv[]) {
    TreeNode *test = NULL;
    test = creat(test);
    Solution sol = Solution();
    cout << sol.findBottomLeftValue(test) << endl;
    return 0;
}
