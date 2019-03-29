//
//  main.cpp
//  784. 字母大小写全排列
//
//  Created by SeacenLiu on 2019/3/29.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
 
 示例:
 输入: S = "a1b2"
 输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
 
 输入: S = "3z4"
 输出: ["3z4", "3Z4"]
 
 输入: S = "12345"
 输出: ["12345"]
 注意：
 
 S 的长度不超过12。
 S 仅由数字和字母组成。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> res;
    void f(int idx, string s) {
        res.push_back(s);
        for (int i = idx; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
                f(i+1, s);
                s[i] += 32;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
                f(i+1, s);
                s[i] -= 32;
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        f(0, S);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    vector<string> res = sol.letterCasePermutation("C");
    for (auto v: res) cout << v << " ";
    cout << endl;
    return 0;
}
