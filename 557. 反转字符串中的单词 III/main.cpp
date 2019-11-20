//
//  main.cpp
//  557. 反转字符串中的单词 III
//
//  Created by SeacenLiu on 2019/11/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 
 示例 1:
 
 输入: "Let's take LeetCode contest"
 输出: "s'teL ekat edoCteeL tsetnoc"
 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

/*
思路：双指针思想，时间复杂度O(n),空间复杂度O(1)。
使用front跟back指向单词的首尾，然后反转并更新两个指针的值
 */
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0){
            return s;
        }
        int front = 0; // 要反转的单词的首字母
        int back = 0; // 要反转的单词的末字母的下一位
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] != ' ') {
                ++back;
            } else {
                reverse(s.begin() + front, s.begin() + back);
                // 当前back指向空格，所以front要从空格的下一个即下一个单词的首字母开始
                front = back + 1;
                // front跟back同一线
                back = front;
            }
        }
        // 此时最后一部分还没有反转，因为s的末尾不是空格，所以此时back应等于最后一个单词的末字母
        ++back;
        // reverse的最后一个参数是要反转的结尾的下一位，back指向s的最后一位，所以要+1
        reverse(s.begin() + front, s.begin() + back);
        return s;
    }
};

/** 先分割单词，再逐一反转
 时间复杂度： O(n) 。其中 n 是字符串的长度。
 空间复杂度： O(n) 。使用了大小为 n 的 res
 */
class Solution2 {
private:
    vector<string> split(string s) {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        words.push_back(word);
        return words;
    }
    string reverse(string s) {
        int l = (int)s.size();
        for (int i = 0; i < l >> 1; ++i) {
            swap(s[i], s[l-i-1]);
        }
        return s;
    }
public:
    string reverseWords(string s) {
        vector<string> words = split(s);
        string res = "";
        for (int i = 0; i < words.size(); ++i) {
            if (!res.empty()) {
                res += ' ';
            }
            res += reverse(words[i]);
        }
        return res;
    }
};

// 方法一: 分割单词，逐一反转
class Solution1 {
private:
    string reverse(string &s) {
        int l = (int)s.size();
        for (int i = 0; i < l >> 1; ++i) {
            swap(s[i], s[l-i-1]);
        }
        return s;
    }
public:
    string reverseWords(string s) {
        vector<string> words;
        string res;
        string tmp = "";
        string::iterator p;
        p = s.begin();
        while (p != s.end()) {
            if (*p == ' ') {
                words.push_back(tmp);
                tmp = "";
            } else {
                tmp += *p;
            }
            ++p;
        }
        words.push_back(tmp);
        for (int i = 0; i < words.size(); ++i) {
            reverse(words[i]);
            if (!res.empty()) {
                res += ' ';
            }
            res += words[i];
        }
        return res;
    }
};

void test(string s, string ans) {
    cout << "======================" << endl;
    cout << s << endl;
    cout << ans << endl;
    cout << Solution().reverseWords(s) << endl;
    cout << "======================" << endl;
}

int main(int argc, const char * argv[]) {
    test("", "");
    test("A", "A");
    test("ABS", "SBA");
    test("Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc");
    std::cout << "Hello, World!\n";
    return 0;
}
