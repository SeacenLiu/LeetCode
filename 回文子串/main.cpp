//
//  main.cpp
//  回文子串
//
//  Created by SeacenLiu on 2018/11/28.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 
 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
 
 示例 1:
 
 输入: "abc"
 输出: 3
 解释: 三个回文子串: "a", "b", "c".
 示例 2:
 
 输入: "aaa"
 输出: 6
 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 注意:
 
 输入的字符串长度不会超过1000。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        for (int i = 0; i < s.length(); ++i) {
            extendSubstrings(s, i, i);  //以 s(i) 为中心向两边扩散
            extendSubstrings(s, i, i+1);  //以 s(i) 与 s(i+1) 为中心向两边扩散
        }
        return cnt;
    }
private:
    int cnt = 0;
    void extendSubstrings(string s, int start, int end) {
        while (start >=0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
            cnt++;
        }
    }
};

int main(int argc, const char * argv[]) {
    cout << Solution().countSubstrings("aaa") << endl;
    cout << Solution().countSubstrings("") << endl;
    cout << Solution().countSubstrings("a") << endl;
    cout << Solution().countSubstrings("abc") << endl;
    cout << Solution().countSubstrings("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
    cout << Solution().countSubstrings("aaaaa") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 dp[i+1,j-1], str[i] = str[j]
 dp[i,j] =
 0, str[i] != str[j]
 */
/* 28ms
 class Solution {
 public:
 int countSubstrings(string s) {
 int len = (int)s.size();
 if (len <= 0) return 0;
 if (len == 1) return 1;
 vector<vector<int>> dp(len, vector<int>(len));
 int sum = 0;
 for (int i = 0; i < len; ++i) {
 dp[i][i] = 1;
 sum++;
 if (i < len-1) {
 if (s[i] == s[i+1]) {
 dp[i][i+1] = 1;
 sum++;
 }
 }
 }
 for (int l = 3; l <= len; ++l) {
 for (int i = 0; i <= len-l; ++i) {
 int j = i + l - 1;
 if (s[i] == s[j] && dp[i+1][j-1] == 1) {
 dp[i][j] = 1;
 sum++;
 }
 }
 }
 return sum;
 }
 };
 */
