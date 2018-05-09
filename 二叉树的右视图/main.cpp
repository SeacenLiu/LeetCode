//
//  main.cpp
//  二叉树的右视图
//
//  Created by SeacenLiu on 2018/5/8.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 
 示例:
 输入: [1,2,3,null,5,null,4]
 输出: [1, 3, 4]
 解释:
    1            <---
  /   \
 2     3         <---
  \     \
   5     4       <---
 */

/**
 * 二叉树的每一层的最后一个结点（从左到右）
 * 既然二叉树分层次，就需要利用层次遍历遍历二叉树
 * 层次遍历二叉树的时候，最重要的内容是知道当前遍历的层哪个是最后一个结点
 * 设置变量记录当前层在遍历队列中剩下的结点书——thisLevelRemaind，
   和下一层一共有多少个结点数——nextLevelHas，这样的话每当对头出队，thisLevelRemaind--，
   每当有新节点入队，nextLevelHas++
 * 最后，如果thisLevelRemaind为1时，则把该结点加入结果集合中
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret = vector<int>();
        if (root == NULL) {
            return ret;
        }
        vector<TreeNode*> queue = vector<TreeNode*>();
        queue.push_back(root);
        TreeNode *bt = root;
        int thisLevelRemaind = 1;
        int nextLevelHas = 0;
        while (!queue.empty()) {
            bt = queue[0];
            
            if (bt->left) {
                queue.push_back(bt->left);
                nextLevelHas++;
            }
            if (bt->right) {
                
                queue.push_back(bt->right);
                nextLevelHas++;
            }
            
            if (thisLevelRemaind == 1) {
                ret.push_back(bt->val);
            }
            
            queue.erase(queue.begin());
            thisLevelRemaind--;
            
            if (thisLevelRemaind == 0) {
                thisLevelRemaind = nextLevelHas;
                nextLevelHas = 0;
            }
        }
        return ret;
    }
};

// 2 1 # # 3 # #
// 1 2 # # 3 4 # # 5 # #
// 1 2 # 5 # # 3 # 4 # #
// 1 2 # 5 # # 3 # #
int main(int argc, const char * argv[]) {
    TreeNode *test = NULL;
    test = creat(test);
    Solution sol = Solution();
    vector<int> ans = sol.rightSideView(test);
    for (int i = 0; i < ans.end()-ans.begin(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

/** 5ms 的其他解题思路
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<TreeNode*> walkv;
        vector<int> v;
        walkv.push_back(root);
        int i = 0, j = 1;
        while (i != walkv.size())
        {
            v.push_back(walkv.back()->val);
            j = (int)walkv.size();
            for (int k = i; k < j; k++)
            {
                if (walkv[k]->left) walkv.push_back(walkv[k]->left);
                if (walkv[k]->right) walkv.push_back(walkv[k]->right);
            }
            i = j;
        }
        return v;
    }
};
*/
