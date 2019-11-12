//
//  main.cpp
//  101. 对称二叉树
//
//  Created by SeacenLiu on 2019/11/12.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二叉树，检查它是否是镜像对称的。

 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 // {1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1}

     1
    / \
   2   2
  / \ / \
 3  4 4  3
 
 
 
 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 // {1,2,-1,3,-1,-1,2,-1,3,-1,-1}

     1
    / \
   2   2
    \   \
    3    3
 说明:

 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/symmetric-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
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

// 使用队列进行迭代处理
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *t1 = queue.front();
            queue.pop();
            TreeNode *t2 = queue.front();
            queue.pop();
            if (t1 == nullptr && t2 == nullptr)
                continue;
            if (t1 == nullptr || t2 == nullptr)
                return false;
            if (t1->val != t2->val)
                return false;
            queue.push(t1->left);
            queue.push(t2->right);
            queue.push(t2->left);
            queue.push(t1->right);
        }
        return true;
    }
};

/** 递归
 时间复杂度：O(n)，因为我们遍历整个输入树一次，所以总的运行时间为 O(n)，其中 nn 是树中结点的总数。
 空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为 O(n)。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为 O(n)。
 */
//class Solution {
//private:
//    bool isMirror(TreeNode *lt, TreeNode *rt) {
//        if (lt == nullptr && rt == nullptr)
//            return true;
//        if (lt == nullptr || rt == nullptr)
//            return false;
//        return lt->val == rt->val &&
//        isMirror(lt->left, rt->right) &&
//        isMirror(lt->right, rt->left);
//    }
//public:
//    bool isSymmetric(TreeNode* root) {
//        return isMirror(root, root);
//    }
//};

void test(vector<int> a) {
    cout << "=========================" << endl;
    TreeNode *p = TreeCreator().createTree(a);
    cout << Solution().isSymmetric(p) << endl;
    cout << "=========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1});
    test({1,2,-1,3,-1,-1,2,-1,3,-1,-1});
    std::cout << "Hello, World!\n";
    return 0;
}
