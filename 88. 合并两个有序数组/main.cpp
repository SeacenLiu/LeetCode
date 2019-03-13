//
//  main.cpp
//  88. 合并两个有序数组
//
//  Created by SeacenLiu on 2019/3/13.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 输出: [1,2,2,3,5,6]
 */

/**
 - 反过来想!!!
 - 从后面开始比对，选最大！
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int i = m-1, j = n-1; // 从后开始比较
        while (j >= 0) { // nums2的都插入完毕就结束了
            if (i < 0) { // 剩下的nums2都是小的
                for (; j >=0; --j) {
                    nums1[j] = nums2[j];
                }
                break;
            }
            if (nums1[i] > nums2[j]) {
                nums1[i+j+1] = nums1[i];
                --i;
            } else {
                nums1[i+j+1] = nums2[j];
                --j;
            }
        }
    }
};

void test(vector<int> nums1, int m, vector<int> nums2, int n) {
    cout << "-------------------------" << endl;
    for (auto v: nums1) cout << v << " ";
    cout << endl;
    for (auto v: nums2) cout << v << " ";
    cout << endl;
    Solution sol = Solution();
    sol.merge(nums1, m, nums2, n);
    for (auto v: nums1) cout << v << " ";
    cout << endl;
    cout << "-------------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({2,4,6,0,0,0}, 3, {1,3,5}, 3);
    test({1,3,5,0,0,0}, 3, {2,4,6}, 3);
    test({4,5,6,0,0,0}, 3, {1,2,3}, 3);
    test({1,2,3,0,0,0}, 3, {2,5,6}, 3);
    test({1}, 1, {}, 0);
    test({0}, 0, {1}, 1);
    return 0;
}
