//
//  main.cpp
//  电话号码的字母组合
//
//  Created by SeacenLiu on 2018/8/10.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 
 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 
 1           2[a,b,c]   3[d,e,f]
 4[g,h,i]    5[j,k,l]   6[m,n,o]
 7[p,q,r,s]  8[t,u,v]   9[w,x,y,z]
 
 示例:
 
 输入："23"
 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 说明:
 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<char>> values = {
        {},{},{'a','b','c'},{'d','e','f'},
        {'g','h','i'},{'j','k','l'},{'m','n','o'},
        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
    };
    vector<string> ret = {};
    void backtracking(vector<int>digits, string cur, int index, int total) {
        if (cur.length() == total) {
            ret.push_back(cur);
            return;
        }
        if (cur.length() < total && values[digits[index]].size() == 0) {
            backtracking(digits, cur, index+1, total);
        }
        for (int i = 0; i < values[digits[index]].size(); i++) {
            cur += values[digits[index]][i];
            backtracking(digits, cur, index+1, total);
            cur = cur.substr(0, cur.length()-1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return ret;
        vector<int> nums = {};
        int temp, total = 0;
        for (auto ch: digits) {
            temp = ch - 48;
            if (temp != 0 && temp != 1) {
                total++;
            }
            nums.push_back(temp);
        }
        backtracking(nums, "", 0, total);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string digits = "23";
    Solution sol = Solution();
    vector<string> ret = sol.letterCombinations(digits);
    for (auto str: ret) {
        cout << str << endl;
    }
    cout << "\nok\n";
    return 0;
}
