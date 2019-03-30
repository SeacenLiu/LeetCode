//
//  main.cpp
//  842. 将数组拆分成斐波那契序列
//
//  Created by SeacenLiu on 2019/3/30.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
 
 形式上，斐波那契式序列是一个非负整数列表 F，且满足：
 
 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
 F.length >= 3；
 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
 
 返回从 S 拆分出来的所有斐波那契式的序列块，如果不能拆分则返回 []。
 
 示例 1：
 
 输入："123456579"
 输出：[123,456,579]
 示例 2：
 
 输入: "11235813"
 输出: [1,1,2,3,5,8,13]
 示例 3：
 
 输入: "112358130"
 输出: []
 解释: 这项任务无法完成。
 示例 4：
 
 输入："0123"
 输出：[]
 解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
 示例 5：
 
 输入: "1101111"
 输出: [110, 1, 111]
 解释: 输出 [11,0,11,11] 也同样被接受。
 提示：
 
 1 <= S.length <= 200
 字符串 S 中只含有数字.
 */

/**
 - 回溯法
    - 先确定前两个数字
    - 大数问题：相加的时候需要检测越界
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
private:
    void s2i(string& s, int& i) {
        stringstream ss(s);
        ss >> i;
    }
    
    bool isValid(string str) {
        int tmp;
        s2i(str, tmp);
        if (tmp == INT_MAX && str != "2147483647")
            return false;
        if (tmp < 0)
            return false;
        if ((str.size() > 1) && str[0] == '0')
            return false;
        return true;
    }
    
    bool isSequece2(vector<int> &res, int cur) {
        if (res.size() >= 2) {
            if (INT_MAX - res[res.size() - 1] < res[res.size() - 2])
                return false;
            if ((res[res.size() - 1] + res[res.size() - 2]) == cur) {
                return true;
            }
        }
        return false;
    }
    
    void f(int idx, vector<int>& cur, string s, vector<int>& res) {
        if (idx == s.size()) {
            if (cur.size() >= 3) {
                res = cur;
            }
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            string sub = s.substr(idx, i-idx+1);
            if (isValid(sub) == false)
                break;
            int tmp;
            s2i(sub, tmp);
            if (cur.size() < 2) {
                cur.push_back(tmp);
                f(i+1, cur, s, res);
                cur.pop_back();
            } else if (isSequece2(cur, tmp)) {
                cur.push_back(tmp);
                f(i+1, cur, s, res);
                cur.pop_back();
            }
        }
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res = {};
        vector<int> tmp = {};
        f(0, tmp, S, res);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    
    vector<int> res = sol.splitIntoFibonacci("123456579");
    for (auto v: res) cout << v << " ";
    cout << endl;
    
    vector<int> res1 = sol.splitIntoFibonacci("0123");
        for (auto v: res1) cout << v << " ";
        cout << endl;
    
    vector<int> res2 = sol.splitIntoFibonacci("214748364721474836422147483641");
        for (auto v: res2) cout << v << " ";
        cout << endl;
    return 0;
}
