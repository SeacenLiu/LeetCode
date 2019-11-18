//
//  main.cpp
//  167. 两数之和 II - 输入有序数组
//
//  Created by SeacenLiu on 2019/11/18.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

 说明:

 返回的下标值（index1 和 index2）不是从零开始的。
 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 示例:

 输入: numbers = [2, 7, 11, 15], target = 9
 输出: [1,2]
 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

// 方法二: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = (int)numbers.size()-1, tmp;
        while (i < j) {
            tmp = numbers[i] + numbers[j];
            if (tmp < target) {
                ++i;
            } else if (tmp > target) {
                --j;
            } else {
                return {i+1, j+1};
            }
        }
        return {};
    }
};

// 方法一: O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                int cur = numbers[i] + numbers[j];
                if (cur == target) {
                    return {i+1, j+1};
                } else if (cur > target) {
                    break;
                }
            }
        }
        return {};
    }
};

void test(vector<int> numbers, int target) {
    cout << "==============================================" << endl;
    for (auto val: numbers) cout << val << " ";
    cout << endl;
    cout << "target: " << target << endl;
    vector<int> res = Solution().twoSum(numbers, target);
    for (auto val: res) cout << val << " ";
    cout << endl;
    cout << "==============================================" << endl;
}

int main(int argc, const char * argv[]) {
    test({0, 1}, 9);
    test({}, 9);
    test({2, 7, 11, 15}, 9);
    std::cout << "Hello, World!\n";
    return 0;
}
