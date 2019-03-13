//
//  main.cpp
//  136. 只出现一次的数字
//
//  Created by SeacenLiu on 2019/3/14.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 
 说明：
 
 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 
 示例 1:
 
 输入: [2,2,1]
 输出: 1
 示例 2:
 
 输入: [4,1,2,1,2]
 输出: 4
 */

/**
 - 思路一: 排序 + 遍历
 - 思路二: 集合去重
 - 思路三: 异或法
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= nums[i];
        }
        return num;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end())
                set.erase(nums[i]);
            else
                set.insert(nums[i]);
        }
        return *set.begin();
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i+=2) {
            if (nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};

void test(vector<int> nums) {
    cout << Solution().singleNumber(nums) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({2,2,1});
    test({4,1,2,1,2});
    return 0;
}
