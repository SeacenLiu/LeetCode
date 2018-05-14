//
//  main.cpp
//  在二叉树中增加一行
//
//  Created by SeacenLiu on 2018/5/14.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。
 添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。
 将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。
 如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。
 
 示例 1:
 
 输入:
 二叉树如下所示:
      4
    /   \
   2     6
  / \   /
 3   1 5
 v = 1
 d = 2
 输出:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5
 
 示例 2:
 输入:
 二叉树如下所示:
     4
    /
   2
  / \
 3   1
 v = 1
 d = 3
 输出:
       4
      /
     2
    / \
   1   1
  /     \
 3       1
 
 注意:
 输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
 输入的二叉树至少有一个节点。
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
 * 本身就可以使用递归
 * 二叉树的题目思考重点：root不一定是第一层的，可以直接看成动态的根结点，每个节点都可以看成根结点
 * deep的值可以用于做处理
 */
/** 16ms */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root==NULL) return NULL;
        if(d==1){
            TreeNode* r = new TreeNode(v);
            r->left = root;
            return r;
        }
        else if(d==2){
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            
            l->left = root->left;
            root->left = l;
            
            r->right = root->right;
            root->right = r;
            
            return root;
        }
        else {
            addOneRow(root->left,v,d-1);
            addOneRow(root->right,v,d-1);
            return root;
        }
    }
};

/**
 * 如何知道在第几层
 */
/** 我的答案 20ms
class Solution {
private:
    void addNew(TreeNode* bt, int v, bool isLeft) {
        TreeNode *newBt = new TreeNode(v);
        if (isLeft) {
            newBt->left = bt->left;
            bt ->left = newBt;
        } else {
            newBt->right = bt->right;
            bt ->right = newBt;
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d < 1) {
            return root;
        }
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        vector<TreeNode*> queue = vector<TreeNode*>();
        TreeNode *bt = root;
        int level = 1;
        int thisLevelRemaind = 1;
        int nextLevelHas = 0;
        queue.push_back(root);
        while (!queue.empty()) {
            if (level > d-1) {
                break;
            }
            bt = queue[0];
            queue.erase(queue.begin());
            if (level == d-1) {
                addNew(bt, v, true);
                addNew(bt, v, false);
                continue;
            }
            if (bt->left) {
                queue.push_back(bt->left);
                nextLevelHas++;
            }
            if (bt->right) {
                queue.push_back(bt->right);
                nextLevelHas++;
            }
            thisLevelRemaind--;
            if (thisLevelRemaind == 0) {
                thisLevelRemaind = nextLevelHas;
                level++;
                nextLevelHas = 0;
            }
        }
        return root;
    }
};
*/

// 2 1 # # 3 # #
// 1 2 # # 3 4 # # 5 # #
// 1 2 # 5 # # 3 # 4 # #
// 1 2 # 5 # # 3 # #
// 4 2 3 # # 1 # # 6 5 # # #
// 4 2 3 # # 1 # # #
// 1 2 4 # # # 3 # #
int main(int argc, const char * argv[]) {
    TreeNode *test = NULL;
    test = creat(test);
    Solution sol = Solution();
    TreeNode *ret = sol.addOneRow(test, 5, 4);
    return 0;
}
