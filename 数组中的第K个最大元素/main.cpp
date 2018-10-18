//
//  main.cpp
//  数组中的第K个最大元素
//
//  Created by SeacenLiu on 2018/10/18.
//  Copyright © 2018 成. All rights reserved.
//

/**
 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 示例 1:

 输入: [3,2,1,5,6,4] 和 k = 2
 输出: 5
 示例 2:

 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 输出: 4
 说明:

 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//快速选择 ：时间复杂度 O(N)，空间复杂度 O(1)
class Solution {
private:
    int partition(vector<int> &a, int l, int h) {
        int i = l, j = h + 1;
        while (true) {
            while (a[++i] < a[l] && i < h);
            while (a[--j] > a[l] && j > l);
            if (i >= j)
                break;
            swap(a[i], a[j]);
        }
        swap(a[l], a[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        k = (int)nums.size() - k; // 倒数第k个位置
        int l = 0, h = (int)nums.size()-1;
        while (l < h) {
            int j = partition(nums, l, h);
            if (j == k)
                break;
            else if (j < k)
                l = j + 1;
            else
                h = j - 1;
        }
        return nums[k];
    }
};

/** 堆排序 ：时间复杂度 O(NlogK)，空间复杂度 O(K)。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        priority_queue <int,vector<int>,greater<int>> pq;
        for (auto i: nums) {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
 */

/** 时间复杂度 O(NlogN)，空间复杂度 O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
 */

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<int> a1 = {3,2,1,5,6,4};
    cout << "{3,2,1,5,6,4}" << endl;
    cout << sol.findKthLargest(a1, 2) << endl;
    vector<int> a2 = {3,2,3,1,2,4,5,5,6};
    cout << "{3,2,3,1,2,4,5,5,6}" << endl;
    cout << sol.findKthLargest(a2, 4) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
