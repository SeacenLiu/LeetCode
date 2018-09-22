//
//  main.cpp
//  字符串相乘
//
//  Created by SeacenLiu on 2018/9/22.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 
 示例 1:
 
 输入: num1 = "2", num2 = "3"
 输出: "6"
 示例 2:
 
 输入: num1 = "123", num2 = "456"
 输出: "56088"
 说明：
 
 num1 和 num2 的长度小于110。
 num1 和 num2 只包含数字 0-9。
 num1 和 num2 均不以零开头，除非是数字 0 本身。
 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trans(char &i) {
        return i - '0';
    }
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        if (l1 < 1 || l2 < 1) return "";
        string res(l1+l2, '0');
        int add, mul, sum;
        for (int i = l1-1; i >= 0; i--) {
            add = 0;
            for (int j = l2 - 1; j >= 0; j--) {
                mul = trans(num1[i]) * trans(num2[j]);
                sum = trans(res[i+j+1])+add+mul%10;
                res[i+j+1] = '0' + sum%10;
                add = mul/10+sum/10;
            }
            res[i]+=add;
        }
        cout << res << endl;
        for(int i=0;i<l1+l2;i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    cout << sol.multiply("2", "3") << endl;
    cout << sol.multiply("123", "456") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
