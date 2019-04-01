//
//  main.cpp
//  131. 分割回文串
//
//  Created by SeacenLiu on 2019/4/1.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 
 返回 s 所有可能的分割方案。
 
 示例:
 
 输入: "aab"
 输出:
 [
    ["aa","b"],
    ["a","a","b"]
 ]
 */

/**
 - DFS + 回溯法
    - 子串
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1])
                return false;
        }
        return true;
    }
    void f(int pos, string str, vector<string>& cur, string s) {
        if (pos > s.size())
            return;
        if (pos == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            string tmp = s.substr(pos, i-pos+1);
            if (isPalindrome(tmp)) {
                cur.push_back(tmp);
                f(i+1, tmp, cur, s);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        f(0, "", cur, s);
        return res;
    }
};

void test(string s) {
    cout << "-----------------" << endl;
    cout << s << endl;
    Solution sol = Solution();
    vector<vector<string>> res = sol.partition(s);
    for (auto arr: res) {
        for (auto v: arr) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test("aab");
    test("abbab");
    return 0;
}
