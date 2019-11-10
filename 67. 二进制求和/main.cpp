//
//  main.cpp
//  67. 二进制求和
//
//  Created by SeacenLiu on 2019/11/10.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定两个二进制字符串，返回他们的和（用二进制表示）。

 输入为非空字符串且只包含数字 1 和 0。

 示例 1:

 输入: a = "11", b = "1"
 输出: "100"
 示例 2:

 输入: a = "1010", b = "1011"
 输出: "10101"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-binary
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int al = (int)a.size();
        int bl = (int)b.size();
        while(al < bl) {
            a = '0' + a;
            ++ al;
        }
        while(al > bl) {
            b = '0' + b;
            ++ bl;
        }
        for(int j = al - 1; j > 0; --j) {
            a[j] = a[j] - '0' + b[j];
            if(a[j] >=  '2') {
                a[j] = (a[j] - '0') % 2 + '0';
                a[j-1] = a[j-1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if(a[0] >= '2') {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};

void test(string a, string b) {
    cout << "========================" << endl;
    cout << "a: " << a << "   " << "b: " << b << endl;
    cout << Solution().addBinary(a, b) << endl;
    cout << "========================" << endl;
}

int main(int argc, const char * argv[]) {
    test("11", "1");
    test("1010", "1011");
    std::cout << "Hello, World!\n";
    return 0;
}
