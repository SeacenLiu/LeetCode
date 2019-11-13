//
//  main.cpp
//  108. 将有序数组转换为二叉搜索树
//
//  Created by SeacenLiu on 2019/11/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

 示例:

 给定有序数组: [-10,-3,0,5,9],

 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

       0
      / \
    -3   9
    /   /
  -10  5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
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

class Solution {
private:
    TreeNode* core(int left, int right, vector<int>& nums) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        cout << left << " " << right << " " << mid << " " << nums[mid] << endl;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = core(left, mid-1, nums);
        root->right = core(mid+1, right, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return core(0, (int)nums.size()-1, nums);
    }
};

void test(vector<int> arr) {
    cout << "================" << endl;
    TreeNode *res = Solution().sortedArrayToBST(arr);
    cout << "================" << endl;
}

int main(int argc, const char * argv[]) {
    test({-10,-3,0,5,9});
    std::cout << "Hello, World!\n";
    return 0;
}
