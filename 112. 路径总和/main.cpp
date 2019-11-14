//
//  main.cpp
//  112. 路径总和
//
//  Created by SeacenLiu on 2019/11/14.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

 说明: 叶子节点是指没有子节点的节点。

 示例:
 给定如下二叉树，以及目标和 sum = 22，
 // {5,4,11,7,-1,-1,2,-1,-1,,-1,8,-13,-1,-1,4,-1,1,-1,-1}

               5
              / \
             4   8
            /   / \
           11  13  4
          /  \      \
         7    2      1
 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/path-sum
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

class Solution {
private:
    bool flag = false;
    void core(TreeNode* root, int sum) {
        if (root == nullptr) {
            return;
        }
        sum -= root->val;
        if (sum == 0) {
            if (root->left == nullptr && root->right == nullptr) {
                flag = true;
            }
        }
        core(root->left, sum);
        core(root->right, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        core(root, sum);
        return flag;
    }
};

void test(vector<int> pa, int num) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(pa);
    cout << Solution().hasPathSum(p, num) << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,-1,-1,-1}, 1);
    test({-2,-3,-1,-1,-1}, -5);
    test({5,4,11,7,-1,-1,2,-1,-1,-1,8,-13,-1,-1,4,-1,1,-1,-1}, 22);
    std::cout << "Hello, World!\n";
    return 0;
}
