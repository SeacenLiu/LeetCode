//
//  main.cpp
//  最长回文子串
//
//  Created by SeacenLiu on 2018/10/10.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
 
 示例 1：
 
 输入: "babad"
 输出: "bab"
 注意: "aba"也是一个有效答案。
 示例 2：
 
 输入: "cbbd"
 输出: "bb"
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 对于字符串str，假设dp[i,j]=1表示str[i...j]是回文子串，那个必定存在dp[i+1,j-1]=1。
 这样最长回文子串就能分解成一系列子问题，可以利用动态规划求解了
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int len = (int)s.size();
        if (len == 1) return s;
        int longest = 1;
        int start = 0;
        vector<vector<int>> dp(len, vector<int>(len)); // 记录 i 到 j 是否是回文
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
            if (i<len-1) {
                if (s[i] == s[i+1]) {
                    dp[i][i+1] = 1;
                    start = i;
                    longest = 2;
                }
            }
        }
        for (int l = 3; l <= len; ++l) { // 子串长度
            for (int i = 0; i+l-1 < len; ++i) { // 枚举子串的起始点
                int j = l + i - 1; // 终点
                if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    longest = l;
                }
            }
        }
        return s.substr(start, longest);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol = Solution();
    
    cout << sol.longestPalindrome("a") << endl;
    cout << sol.longestPalindrome("aa") << endl;
    cout << sol.longestPalindrome("babad") << endl; // --
    cout << sol.longestPalindrome("cbbd") << endl;
    cout << sol.longestPalindrome("abcdbbfcba") << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}

/* 有问题的解法
 class Solution {
 public:
 string longestPalindrome(string s) {
 if (s.empty()) return "";
 int len = (int)s.size();
 if (len == 1) return s;
 int longest = 1;
 int start = 0;
 vector<vector<int>> dp(len, vector<int>(len));
 for (int i = 0; i < len; i++)
 {
 dp[i][i] = 1;
 if (i < len-1)
 {
 if (s[i] == s[i+1])
 {
 dp[i][i+1] = 1;
 start = i;
 longest = 2;
 }
 }
 }
 for (int l = 3; l <= len; l++) //子串长度
 {
 for (int i = 0; i+l-1 < len; i++) // 枚举子串w起始点
 {
 int j = l+i+1; // 终点
 if (s[i] == s[j] && dp[i+1][j-1] == 1)
 {
 dp[i][j] = 1;
 start = i;
 longest = l;
 }
 }
 }
 return s.substr(start,longest);
 }
 };
 */

/* 超时啊 暴力解法
 时间复杂度: (n / 2) * n * (n(n+1)/2) => n^3 => O(n^3)
 空间复杂度: O(1)
class Solution {
private:
    bool valid(string s) {
        unsigned long length = s.size();
        for (int i = 0; i < length / 2; i++) // n / 2
            if (s[i] != s[length-i-1])
                return false;
        return true;
    }
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return s;
        string ret;
        string sub;
        for (int i = 0; i < s.size(); i++){ // n
            for (int j = 1; j <= s.size() - i; j++) { // (n(n+1)/2) ->
                sub = s.substr(i, j);
                if (valid(sub) && sub.size() > ret.size())
                    ret = sub;
            }
        }
        return ret;
    }
};
*/

/*
 if (valid(s))
 cout << "true" << endl;
 else
 cout << "false" << endl;
 */
