//
//  main.cpp
//  217. 存在重复元素
//
//  Created by SeacenLiu on 2019/11/18.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个整数数组，判断是否存在重复元素。

 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

 示例 1:

 输入: [1,2,3,1]
 输出: true
 示例 2:

 输入: [1,2,3,4]
 输出: false
 示例 3:

 输入: [1,1,1,3,3,4,3,2,4,2]
 输出: true

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/contains-duplicate
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 方法二: 哈希表 O(n) O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};

// 方法一: 排序后遍历 O(nlogn)
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

void test(vector<int> nums) {
    cout << "============================" << endl;
    for (auto val: nums) cout << val << " ";
    cout << endl;
    cout << Solution().containsDuplicate(nums) << endl;
    cout << "============================" << endl;
}

int main(int argc, const char * argv[]) {
    test({});
    test({1});
    test({1,2});
    test({1,1});
    test({1,2,3,1});
    test({1,2,3,4});
    test({1,1,1,3,3,4,3,2,4,2});
    std::cout << "Hello, World!\n";
    return 0;
}
