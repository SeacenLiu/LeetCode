//
//  main.cpp
//  16. 最接近的三数之和
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

// 16
/**
 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
 找出 nums 中的三个整数，使得它们的和与 target 最接近。
 返回这三个数的和。假定每组输入只存在唯一答案。
 
 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 
 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */

/**
 - 靠近：绝对值比较
 - 思路一：暴力解法 排列组合 超时
 - 思路二：
    - 排序 O(nlogn)
    - 先确定第一个数
    - 使用两个指针前后
    - 比较值，进行前后指针移动，逼近target值
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** O(n^2) */
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int dist = abs(res-target);
        for (int i = 0; i < nums.size()-1; ++i) {
            int j = i+1;
            int k =(int) nums.size()-1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                int curDist = abs(total-target);
                if (curDist < dist) {
                    dist = curDist;
                    res = total;
                }
                if (total == target)
                    return total;
                else if (total > target)
                    --k;
                else
                    ++j;
            }
        }
        return res;
    }
};

/** 超时 */
class Solution1 {
private:
    int res;
    int check = INT_MAX;
    int target;
    vector<int> nums;
    void backtracking(int cur, int cnt, int total) {
        if (cnt == 3) {
            int v = abs(total-target);
            if (v < check) {
                check = v;
                res = total;
            }
            return;
        }
        for (int i = cur; i < nums.size(); ++i) {
            backtracking(i+1, cnt+1, total+nums[i]);
        }
    }
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.empty()) return 0;
        this->nums = nums;
        this->target = target;
        for (int i = 0; i < nums.size()-2; ++i) {
            backtracking(i, 0, 0);
        }
        return res;
    }
};

void test(vector<int> nums, int target) {
    Solution sol = Solution();
    cout << sol.threeSumClosest(nums, target) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({}, 1);
    test({-1,2,1,-4}, 1);
    test({1,1,1,1}, -100);
    test({0,1,2}, 3);
    test({1,1,1,0}, -100);
    test({0,2,1,-3}, 1);
    return 0;
}
