//
//  main.cpp
//  从中序与后序遍历序列构造二叉树
//
//  Created by SeacenLiu on 2018/5/10.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 根据一棵树的中序遍历与后序遍历构造二叉树。
 
 注意:
 你可以假设树中没有重复的元素。
 
 例如，给出:
 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7

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

void coutVector(vector<int>& order) {
    for (int i = 0; i < order.end()-order.begin(); i++) {
        cout << order[i] << endl;
    }
}

/**
 * 找根结点 -> 创建每个小根结点 -> 找左右子树 -> 合并所有小的根结点
 * 1. 根据后序遍历序列的最后一个数字创建根结点（后序遍历序列的最后一个数字就是根结点）
 * 2. 在中序遍历序列中找到根结点所在的位置，这样就能确定左、右子树结点的数量
 * 3. 这样也就分别找到了左、右子树的中序遍历序列和后序遍历序列
 * 4. 用递归的方法去构建左、右子树，直到叶子结点
 */
class Solution {
private:
    int findPosition(vector<int>& order, int start, int end, int key) {
        for (int i = start; i <= end; i++) {
            if (order[i] == key) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode *buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int rootPosition = findPosition(inorder, inStart, inEnd, root->val);
        root->left = buildTree(inorder, inStart, rootPosition-1, postorder, postStart, postStart + (rootPosition-inStart-1));
        root->right = buildTree(inorder, rootPosition + 1, inEnd, postorder, postStart + (rootPosition - inStart), postEnd - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderLength = (int)(inorder.end()-inorder.begin());
        int postorderLength = (int)(postorder.end()-postorder.begin());
        if (inorderLength != postorderLength) {
            return NULL;
        }
        return buildTree(inorder, 0, inorderLength-1, postorder, 0, postorderLength-1);
    }
};

int main(int argc, const char * argv[]) {
    int arr1[] = {9,3,15,20,7};
    vector<int> inorder(arr1, arr1+5);
    int arr2[] = {9,15,7,20,3};
    vector<int> postorder(arr2, arr2+5);
    Solution sol = Solution();
    TreeNode *ret = sol.buildTree(inorder, postorder);
    return 0;
}

