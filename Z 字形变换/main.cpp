//
//  main.cpp
//  Z 字形变换
//
//  Created by SeacenLiu on 2019/3/10.
//  Copyright © 2019 成. All rights reserved.
//

// 6
/**
 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 
 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 
 L   C   I   R
 E T O E S I I G
 E   D   H   N
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 
 请你实现这个将字符串进行指定行数变换的函数：
 
 string convert(string s, int numRows);
 示例 1:
 
 输入: s = "LEETCODEISHIRING", numRows = 3
 输出: "LCIRETOESIIGEDHN"
 示例 2:
 
 输入: s = "LEETCODEISHIRING", numRows = 4
 输出: "LDREOEIIECIHNTSG"
 解释:
 
 L     D     R
 E   O E   I I
 E C   I H   N
 T     S     G
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res = "";
        int size = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j += size) {
                res += s[j];
                int tmp = j + size - 2 * i;
                if (i != 0 && i != numRows - 1 && tmp < s.size()) // 不是初始和结束行
                    res += s[tmp];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.convert("LEETCODEISHIRING", 3) << endl;
    cout << sol.convert("LEETCODEISHIRING", 4) << endl;
    cout << sol.convert("A", 1) << endl;
    return 0;
}
