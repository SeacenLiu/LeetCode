//
//  main.cpp
//  169. 求众数
//
//  Created by SeacenLiu on 2019/3/14.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 
 你可以假设数组是非空的，并且给定的数组总是存在众数。
 
 示例 1:
 
 输入: [3,2,3]
 输出: 3
 示例 2:
 
 输入: [2,2,1,1,1,2,2]
 输出: 2
 */

/**
 - 思路一: 排序 + 取中
 - 思路二: Bit Manipulation
    - 将中位数按位来建立，从0到31位
    - 每次统计下数组中该位上0和1的个数
        - 如果1多，那么我们将结果res中该位变为1
    - 最后累加出来的res就是中位数了
 - 思路三: res + cnt
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// 28ms
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int res = nums[0], cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) { res = nums[i]; ++cnt; }
            else (res == nums[i]) ? ++cnt : --cnt;
        }
        return res;
    }
};

// TODO: - 位操作的方法不太掌握
/// 32ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = (int)nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > n / 2 || zeros > n / 2) break;
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros;
            }
            if (ones > zeros) res |= (1 << i);
        }
        return res;
    }
};

/// 40ms
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};

void test(vector<int> nums) {
    Solution sol = Solution();
    cout << sol.majorityElement(nums) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({});
    test({9});
    test({2,2});
    test({3,2,3});
    test({-1,1,1,1,2,1});
    test({2,2,1,1,1,2,2});
    return 0;
}
