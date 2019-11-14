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
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

class Solution1 {
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

/** 思路清晰的递归
 时间复杂度：我们访问每个节点一次，时间复杂度为 O(N) ，其中 N 是节点个数。
 空间复杂度：
 最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N 次（树的高度），因此栈的空间开销是 O(N) 。
 最好情况下，树是完全平衡的，高度只有 log(N)，因此在这种情况下空间复杂度只有 O(log(N)) 。
 */
class Solution2 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return false;
        sum -= root->val;
        if ((root->left == nullptr) && (root->right == nullptr))
            return (sum == 0);
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

/** 使用栈进行迭代
 时间复杂度：和递归方法相同是 O(N)。
 空间复杂度：
    当树不平衡的最坏情况下是 O(N)
    在最好情况（树是平衡的）下是 O(logN)
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr)
            return false;
        
        stack<TreeNode*> node_stack;
        stack<int> sum_stack;
        node_stack.push(root);
        sum_stack.push(sum - root->val);
        
        TreeNode *node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.top();
            node_stack.pop();
            curr_sum = sum_stack.top();
            sum_stack.pop();
            if ((node->right == nullptr) && (node->left == nullptr) && (curr_sum == 0))
                return true;
            if (node->left != nullptr) {
                node_stack.push(node->left);
                sum_stack.push(curr_sum - node->left->val);
            }
            if (node->right != nullptr) {
                node_stack.push(node->right);
                sum_stack.push(curr_sum - node->right->val);
            }
        }
        return false;
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
