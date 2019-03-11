//
//  main.cpp
//  89. 格雷编码
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 格雷编码是一个二进制数字系统，在该系统中， 两个连续的数值仅有一个位数的差异。
 
 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
 
 示例 1:
 
 输入: 2
 输出: [0,1,3,2]
 解释:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 
 对于给定的 n，其格雷编码序列并不唯一。
 例如，[0,2,3,1] 也是一个有效的格雷编码序列。
 
 00 - 0
 10 - 2
 11 - 3
 01 - 1
 示例 2:
 
 输入: 0
 输出: [0]
 解释: 我们定义格雷编码序列必须以 0 开头。
 给定编码总位数为 n 的格雷编码序列，其长度为 2^n。当 n = 0 时，长度为 2^0 = 1。
 因此，当 n = 0 时，其格雷编码序列为 [0]。
 */

/**
 - 思路一:
    - 除了最高位，剩下的上下对称
    - 递归的编程思想
    - vector<string> last = grayCodeOfString(n-1);
 - 思路二：
    - 找公式：i^(i>>1)
    - 位运算：自己与自己左移一位进行异或，得到的就是它的格雷码
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> res;
        for(int i=0;i<size;i++){
            int graycode = i ^ (i>>1);
            res.push_back(graycode);
        }
        return res;
    }
};

// 思路一
class Solution1 {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) return {0};
        vector<string> strs = grayCodeOfString(n);
        vector<int> res;
        for (int i = 0; i < strs.size(); i++) {
            res.push_back(bitStringToInt(strs[i]));
        }
        return res;
    }
private:
    vector<string> grayCodeOfString(int n) {
        vector<string> strs(pow(2,n), "");
        if (n == 1) {
            strs[0] = "0";
            strs[1] = "1";
            return strs;
        }
        vector<string> last = grayCodeOfString(n-1);
        for (int i = 0; i < last.size(); ++i) {
            strs[i] = "0" + last[i];
            strs[strs.size()-1-i] = "1"+last[i];
        }
        return strs;
    }
    
    int bitStringToInt(string str) {
        int res = 0, pow = 1;
        for (int i = (int)str.size()-1; i >= 0; --i) {
            res += ((str[i]-'0')*pow);
            pow *= 2;
        }
        return res;
    }
};

void test(int n) {
    Solution sol = Solution();
    vector<int> res = sol.grayCode(n);
    for (auto v: res) {
        cout << v << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test(0);
    test(1);
    test(2);
    return 0;
}
