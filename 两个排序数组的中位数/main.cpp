//
//  main.cpp
//  两个排序数组的中位数
//
//  Created by SeacenLiu on 2018/10/30.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
 
 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
 
 你可以假设 nums1 和 nums2 不同时为空。
 
 示例 1:
 
 nums1 = [1, 3]
 nums2 = [2]
 
 中位数是 2.0
 示例 2:
 
 nums1 = [1, 2]
 nums2 = [3, 4]
 
 中位数是 (2 + 3)/2 = 2.5
 */

/**
 * 自己瞎想的:
 * 中位数 => 两个数组合并在一起之后中间的数
 * 将题目转化成:
 *  元素总数是奇数的时候：寻找第 (n/2)+1 个元素
 *  元素总数是偶数的时候：寻找第 (n/2)+1 个元素和第 (n/2)+1 个元素的平均数
 *
 *  分区思想？分治思想？
 *
 *  归并排序
 *  总时间 = 分解时间 + 解决问题时间 + 合并时间
 *  这里只需要 merge
 *
 * 参考答案:
 *  中位数的作用是什么: 将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 时间复杂度：O(log(min(m,n)))  空间复杂度：O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if (m>n) {
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j-1] > nums1[i]) {
                // i is too small
                iMin = i + 1;
            }
            else if (i > iMin && nums1[i-1] > nums2[j]) {
                // i is too big
                iMax = i - 1;
            }
            else {
                // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = nums2[j-1]; }
                else if (j == 0) { maxLeft = nums1[i-1]; }
                else { maxLeft = max(nums1[i-1], nums2[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }
                
                int minRight = 0;
                if (i == m) { minRight = nums2[j]; }
                else if (j == n) { minRight = nums1[i]; }
                else { minRight = min(nums2[j], nums1[i]); }
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

/* 时间复杂度: O(m+n) 空间复杂度: O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = (int)nums1.size();
        int l2 = (int)nums2.size();
        double result = 0;
        int i = 0, j = 0, k = 0;
        vector<int> num(l1+l2);
        while (i < l1 && j < l2) {
            if (nums1[i] < nums2[j])
                num[k++] = nums1[i++];
            else
                num[k++] = nums2[j++];
        }
        while (i == l1 && j < l2) {
            num[k++] = nums2[j++];
        }
        while (i < l1 && j == l2) {
            num[k++] = nums1[i++];
        }
        if (num.size() % 2 == 0)
            result = ((double)(num[num.size() / 2] + num[num.size() / 2 - 1]))/2;
        else
            result = (double)(num[num.size() / 2]);
        return result;
    }
};
 */

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<int> t1 = {1, 2};
    vector<int> t2 = {3, 4};
    cout << sol.findMedianSortedArrays(t1, t2) << endl;
    
    vector<int> t3 = {1, 3};
    vector<int> t4 = {2};
    cout << sol.findMedianSortedArrays(t3, t4) << endl;
    
    vector<int> t5 = {};
    vector<int> t6 = {1};
    cout << sol.findMedianSortedArrays(t5, t6) << endl;
    
    vector<int> t7 = {};
    vector<int> t8 = {1,2};
    cout << sol.findMedianSortedArrays(t7, t8) << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
