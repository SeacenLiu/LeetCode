//
//  main.cpp
//  93. 复原IP地址
//
//  Created by SeacenLiu on 2019/4/2.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 
 示例:
 
 输入: "25525511135"
 输出: ["255.255.11.135", "255.255.111.35"]
 */

/**
 - 重点：
    - 0 ~ 255 的判断
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
private:
    vector<string> res;
    bool isValid(string s) {
        if (s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        if (s.size() < 3)
            return true;
        int i = atoi(s.c_str());
        return (i >= 0) && (i <= 255);
    }
    void f(int pos, vector<string>& cur, string& s) {
        if (pos > s.size() || cur.size() > 4)
            return;
        if (pos == s.size() && cur.size() == 4) {
            string tmp;
            for (int i = 0; i < cur.size(); ++i) {
                tmp += cur[i];
                if (i < cur.size()-1)
                    tmp += '.';
            }
            res.push_back(tmp);
            return;
        }
        for (int i = pos; i < pos+3; ++i) {
            string sub = s.substr(pos, i-pos+1);
            if (isValid(sub)) {
                cur.push_back(sub);
                f(i+1, cur, s);
                cur.pop_back();
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> tmp;
        f(0, tmp, s);
        return res;
    }
};

class Solution1 {
private:
    vector<string> res;
    bool isValid(string s) {
        if (s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        if (s.size() < 3)
            return true;
        int i = atoi(s.c_str());
        return (i >= 0) && (i <= 255);
    }
    void f(int pos, vector<string>& cur, string& s) {
        if (pos > s.size() || cur.size() > 4)
            return;
        if (pos == s.size() && cur.size() == 4) {
            string tmp;
            for (int i = 0; i < cur.size(); ++i) {
                tmp += cur[i];
                if (i < cur.size()-1)
                    tmp += '.';
            }
            res.push_back(tmp);
            return;
        }
        for (int i = pos; i < pos+3; ++i) {
            string sub = s.substr(pos, i-pos+1);
            if (isValid(sub)) {
                cur.push_back(sub);
                f(i+1, cur, s);
                cur.pop_back();
            } else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> tmp;
        f(0, tmp, s);
        return res;
    }
};

void test(string s) {
    cout << "-----------------------" << endl;
    Solution sol = Solution();
    cout << s << endl;
    vector<string> res = sol.restoreIpAddresses(s);
    for (auto v: res) cout << v << endl;
    cout << "-----------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test("25525511135");
    test("010010"); // ["0.10.0.10","0.100.1.0"]
    return 0;
}
