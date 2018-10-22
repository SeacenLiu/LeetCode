//
//  main.cpp
//  寻找重复的子树
//
//  Created by SeacenLiu on 2018/10/21.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 
 两棵树重复是指它们具有相同的结构以及相同的结点值。
 
 示例 1：
 
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4
 下面是两个重复的子树：
 
   2
  /
 4
 和
 
 4
 因此，你需要以列表的形式返回上述重复子树的根结点。
 */

// 前序 1,2,4,4,3,2,4
// 后序 4,4,2,2,4,3,1
// 中序 4,4,2,1,2,3,4

/*
        1
       / \
      2   2
 // pre 1,2,2
 // mid 2,1,2
 // lat 2,2,1
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 前序遍历
 使用unordered_map<string, int>来保存
 
 找到所有子树并记下来
 判断数量
 */

typedef unordered_map<string, int> hash_map;
typedef vector<TreeNode*> node_arr;
class Solution {
private:
    string helper(TreeNode* root, hash_map &map, node_arr &res) {
        if (!root) return "#";
        string str = to_string(root->val) + "," + helper(root->left, map, res) + "," + helper(root->right, map, res);
        if (map.find(str) != map.end()) {
            if (map[str] == 1) res.push_back(root);
            map[str]++;
        } else {
            map[str] = 1;
        }
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        node_arr res;
        hash_map map;
        helper(root, map, res);
        return res;
    }
};

void ShowResult(vector<TreeNode*> arr) {
    for (auto i: arr) {
        cout << i << endl;
    }
}

int main(int argc, const char * argv[]) {
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(2);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n5->left = n7;
    Solution sol = Solution();
    ShowResult(sol.findDuplicateSubtrees(n1));
    std::cout << "Hello, World!\n";
    return 0;
}
