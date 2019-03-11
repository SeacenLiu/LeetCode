//
//  main.cpp
//  124. 二叉树中的最大路径和
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非空二叉树，返回其最大路径和。
 
 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 
 示例 1:
 
 输入: [1,2,3]
 
 1
 / \
 2   3
 
 输出: 6
 示例 2:
 
 输入: [-10,9,20,null,null,15,7]
 
  -10
  / \
 9  20
    /  \
    15   7
 
 输出: 42
 
 */

/**
 - 思路一：
    - 对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:
        - 1. 其左右子树中所构成的和路径值较大的那个加上该节点的值后向父节点回溯构成最大路径
        - 2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径
 **/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int res = INT_MIN;
    int getMax(TreeNode* root) {
        if (root == nullptr) return 0;
        // 左子树到底部的最大和
        int left = max(0, getMax(root->left));
        // 右子树到底部的最大和
        int right = max(0, getMax(root->right));
        // 连接两个最大和
        res = max(res, root->val + left + right);
        // 返回最大和
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        getMax(root);
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
        index = 0;
        return create_tree_core(a);
    }
};

void test(vector<int> arr) {
    Solution sol = Solution();
    TreeNode* root = TreeCreator().createTree(arr);
    cout << sol.maxPathSum(root) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({1,2,-1,-1,3,-1,-1});
    test({-10,9,-1,-1,20,15,-1,-1,7,-1,-1});
    return 0;
}
