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
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, left = 0;
        string sub;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < sub.length(); j++) {
                if (sub[j] == s[i]) {
                    if (sub.length() > max) {
                        max = (int)sub.length();
                    }
                    left = left+j+1;
                    sub = "";
                    for (int k = left; k <= i; k++) {
                        sub += s[k];
                    }
                    goto here;
                }
            }
            sub += s[i];
        here:;
        }
        if (sub.length() > max) {
            max = (int)sub.length();
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
