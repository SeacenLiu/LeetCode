//
//  main.cpp
//  66. 加一
//
//  Created by SeacenLiu on 2019/11/7.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 
 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 示例 2:
 
 输入: [4,3,2,1]
 输出: [4,3,2,2]
 解释: 输入数组表示数字 4321。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = (int)digits.size();
        vector<int> res(length+1, 0);
        int carry = 0, tmp;
        for (int i = length-1; i >= 0; --i) {
            tmp = i == length-1 ? 1 : 0;
            tmp += digits[i] + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            res[i+1] = tmp;
        }
        res[0] = carry > 0 ? carry : res[0];
        if (res[0] == 0) {
            res.erase(res.begin());
        }
        return res;
    }
};

void test(vector<int> digits) {
    cout << "====================" << endl;
    for (auto i: digits) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res = Solution().plusOne(digits);
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    cout << "====================" << endl;
}

int main(int argc, const char * argv[]) {
    test({0});
    test({9});
    test({9,9});
    test({1,2,3});
    test({4,3,2,1});
    std::cout << "Hello, World!\n";
    return 0;
}
