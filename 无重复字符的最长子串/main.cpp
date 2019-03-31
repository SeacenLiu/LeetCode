//
//  main.cpp
//  无重复字符的最长子串
//
//  Created by SeacenLiu on 2018/4/29.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个字符串，找出不含有重复字符的最长子串的长度。
 
 示例：
 给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
 给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
 给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int res = 0, start = 0, len = 0;
        vector<int> map(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == -1 || map[s[i]] < start) {
                ++len;
                map[s[i]] = i;
            } else {
                start = map[s[i]];
                len = i - map[s[i]];
                map[s[i]] = i;
            }
            res = max(res, len);
        }
        return res;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        string temp = "";
        int max = 1;
        int cur = 0;
        for (auto ch: s) {
            int i = (int)temp.find(ch);
            if (i == -1) {
                temp += ch;
                ++cur;
            } else {
                if (cur > max) { max = cur; }
                temp = temp.substr(i+1);
                temp += ch;
                cur = (int)temp.size();
            }
        }
        if (cur > max) { max = cur; }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution1 sol = Solution1();
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    
    Solution sol1 = Solution();
    cout << sol1.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    
    Solution sol2 = Solution();
    cout << sol2.lengthOfLongestSubstring("dvdf") << endl; // 3
    
    Solution sol3 = Solution();
    cout << sol3.lengthOfLongestSubstring("abba") << endl; // 2
    
    Solution sol4 = Solution();
    cout << sol4.lengthOfLongestSubstring("") << endl; // 0
    
    Solution sol5 = Solution();
    cout << sol5.lengthOfLongestSubstring("tmmzuxt") << endl; // 5
    
    Solution sol6 = Solution();
    cout << sol6.lengthOfLongestSubstring(" ") << endl; // 1
    
    return 0;
}
