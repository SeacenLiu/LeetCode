//
//  main.cpp
//  二叉搜索树迭代器
//
//  Created by SeacenLiu on 2018/8/2.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
 
 调用 next() 将返回二叉搜索树中的下一个最小的数。
 
 注意: next() 和hasNext() 操作的时间复杂度是O(1)，并使用 O(h) 内存，其中 h 是树的高度。
 */

// 使用stack -> 将左子树都压栈中 -> 如果栈顶有右子树，压入右子树和其下面的左子树 => 每一个栈顶的元素就是next()
// 而不是vector加后序遍历 -> 这种方法在初始化的时候使用递归十分耗时

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 16ms
class BSTIterator {
public:
    //要求时间复杂度是O(1)，那么应该用数组
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next()
    {
        TreeNode *n = s.top();
        int res = n->val;
        s.pop();
        if (n->right)
        {
            n = n->right;
            while (n)
            {
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
private:
    stack<TreeNode*> s;
};

/** 88ms 自己的
class BSTIterator {
private:
    vector<int> arr;
    int curIndex = 0;
    void postOrder(TreeNode *root) {
        if (root != NULL) {
            postOrder(root->left);
            arr.push_back(root->val);
            postOrder(root->right);
        }
    }
public:
    BSTIterator(TreeNode *root) {
        postOrder(root);
    }

    int length() {
        return (int)arr.size();
    }
 
    bool hasNext() {
        return curIndex < length();
    }

    int next() {
        if (curIndex < length()) {
            return arr[curIndex++];
        }
        return -1;
    }
};
*/

TreeNode* createTree(vector<int> nums) {
    TreeNode *root = new TreeNode(nums[0]);
    TreeNode *p = root;
    int curValue = 0;
    for (int i = 1; i < nums.size(); i++) {
        curValue = nums[i];
        p = root;
        while (1) {
            if (curValue < p->val) {
                if (p->left == NULL) {
                    p->left = new TreeNode(curValue);
                    break;
                }
                p = p->left;
            } else {
                if (p->right == NULL) {
                    p->right = new TreeNode(curValue);
                    break;
                }
                p = p->right;
            }
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = createTree({15, 6, 3, 7, 2, 4, 13, 9, 18, 17, 20});
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << endl;
    return 0;
}
