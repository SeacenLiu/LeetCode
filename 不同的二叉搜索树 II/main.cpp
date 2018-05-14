//
//  main.cpp
//  不同的二叉搜索树 II
//
//  Created by SeacenLiu on 2018/5/13.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 
 示例:
 
 输入: 3
 输出:
 [
 [1,null,3,2],
 [3,2,null,1],
 [3,1,null,null,2],
 [2,1,3],
 [1,null,2,null,3]
 ]
 解释:
 以上的输出对应以下 5 种不同结构的二叉搜索树：
 
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 */

/**
 * 以每个数字为head,然后递归产生就行。
 * 二叉搜索树 -> 小的在左边，大的在右边
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

class Solution {
private:
    vector<TreeNode*> generateTrees(int start,int end) {
        vector<TreeNode*> ret;
        if (start>end) {
            ret.push_back(nullptr);
            return ret;
        }
        if (start==end) {
            ret.push_back(new TreeNode(start));
            return ret;
        }
        for (int i=start;i<=end;i++) {
            vector<TreeNode*> left = generateTrees(start,i-1);
            vector<TreeNode*> right = generateTrees(i+1,end);
            for(auto l:left) {
                for(auto r:right) {
                    TreeNode* head = new TreeNode(i);
                    head->left = l;
                    head->right = r;
                    ret.push_back(head);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        } else {
            return generateTrees(1, n);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<TreeNode*> ret = sol.generateTrees(0);
    cout << ret.end()-ret.begin() << endl;
    return 0;
}
