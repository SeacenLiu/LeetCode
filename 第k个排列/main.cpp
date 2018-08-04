//
//  main.cpp
//  第k个排列
//
//  Created by SeacenLiu on 2018/8/4.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 
 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 给定 n 和 k，返回第 k 个排列。
 
 说明：
 
 给定 n 的范围是 [1, 9]。
 给定 k 的范围是[1,  n!]。
 示例 1:
 
 输入: n = 3, k = 3
 输出: "213"
 示例 2:
 
 输入: n = 4, k = 9
 输出: "2314"
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};   //0到10的阶乘
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums(n);  //存放1到n
        for(int i = 0; i < n; i ++)
            nums[i] = i + 1;
        while(n)
        {
            int max = (k-1) / fact[n-1];
            result += (nums[max] + '0');   //确定最高位
            k -= max * fact[n - 1];
            for(int i = max + 1; i < n; i++)   //将数组nums中比max大的数提前一位
                nums[i - 1] = nums[i];
            nums.pop_back();
            n --;
        }
        return result;
    }
};

/** 1232ms...
class Solution {
private:
    string ret;
    int target;
    void backtracking(vector<int> nums, vector<int> &temp, int n, int k, int index) {
        if (target <= 0) return;
        if (index == nums.size()) {
            if (--target == 0) {
                for (auto i: temp) {
                    ret += to_string(i);
                }
            }
            return;
        }
        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            sort(nums.begin()+i, nums.end());
            temp.push_back(nums[index]);
            backtracking(nums, temp, n, k, index+1);
            temp.pop_back();
            swap(nums[index], nums[i]);
        }
    }
public:
    string getPermutation(int n, int k) {
        target = k;
        vector<int> nums = {};
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        vector<int> temp = {};
        backtracking(nums, temp, n, k, 0);
        return ret;
    }
};
*/
int main(int argc, const char * argv[]) {
    int n = 3;//3;
    int k = 5;//5;
    Solution sol = Solution();
    cout << sol.getPermutation(n, k) << endl;
    return 0;
}
