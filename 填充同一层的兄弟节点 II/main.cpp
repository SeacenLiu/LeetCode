//
//  main.cpp
//  填充同一层的兄弟节点 II
//
//  Created by SeacenLiu on 2018/5/7.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个二叉树
 struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
 }
 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 
 初始状态下，所有 next 指针都被设置为 NULL。
 
 说明:
 你只能使用额外常数空间。
 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 
 示例:
 给定二叉树，
 
    1
   /  \
  2    3
 / \    \
4   5    7
 调用你的函数后，该二叉树变为：
 
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL
 */

#include <iostream>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *pre = dummy;
        while(root != NULL) {
            if(root->left != NULL) {
                pre->next = root->left;
                pre = pre->next;
            }
            if(root->right != NULL) {
                pre->next = root->right;
                pre = pre->next;
            }
            root = root->next;
            // done with the search of current level
            if(root == NULL) {
                root = dummy->next;
                pre = dummy;
                dummy->next = NULL;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    
    TreeLinkNode node1 = TreeLinkNode(1);
    TreeLinkNode node2 = TreeLinkNode(2);
    TreeLinkNode node3 = TreeLinkNode(3);
    TreeLinkNode node4 = TreeLinkNode(4);
    TreeLinkNode node5 = TreeLinkNode(5);
    TreeLinkNode node6 = TreeLinkNode(6);
    TreeLinkNode node7 = TreeLinkNode(7);
    TreeLinkNode node8 = TreeLinkNode(8);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.right = &node6;
    node4.left = &node7;
    node6.right = &node8;
    
    sol.connect(&node1);
    
    return 0;
}
