//
//  main.cpp
//  107. 二叉树的层次遍历 II
//
//  Created by SeacenLiu on 2019/11/12.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

 例如：
 给定二叉树 [3,9,20,null,null,15,7],
 // {3,9,-1,-1,20,15,-1,-1,7,-1,-1}

     3
    / \
   9  20
     /  \
    15   7
 返回其自底向上的层次遍历为：

 [
   [15,7],
   [9,20],
   [3]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        stack<vector<int>> stack;
        queue.push(root);
        int curLevel = 1;
        int nextLevel = 0;
        vector<int> levelArr;
        while (!queue.empty()) {
            TreeNode *t = queue.front();
            queue.pop();
            levelArr.push_back(t->val);
            --curLevel;
            if (t->left) {
                queue.push(t->left);
                ++nextLevel;
            }
            if (t->right) {
                queue.push(t->right);
                ++nextLevel;
            }
            if (curLevel == 0) {
                stack.push(levelArr);
                levelArr.clear();
                curLevel = nextLevel;
                nextLevel = 0;
            }
        }
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }
        return res;
    }
};

void test(vector<int> arr) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(arr);
    vector<vector<int>> res = Solution().levelOrderBottom(p);
    for (auto level: res) {
        for (auto val: level) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({3,9,-1,-1,20,15,-1,-1,7,-1,-1});
    test({-1});
    std::cout << "Hello, World!\n";
    return 0;
}
