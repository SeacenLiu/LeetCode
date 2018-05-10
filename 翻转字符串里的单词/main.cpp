//
//  main.cpp
//  翻转字符串里的单词
//
//  Created by SeacenLiu on 2018/5/10.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个字符串，逐个翻转字符串中的每个单词。
 
 示例:
 输入: "the sky is blue",
 输出: "blue is sky the".
 说明:
 无空格字符构成一个单词。
 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
 进阶: 请选用C语言的用户尝试使用 O(1) 时间复杂度的原地解法。
 */

#include <iostream>
#include <vector>
using namespace std;

/** 8ms 自己的
class Solution {
public:
    void reverseWords(string &s) {
        string str = string();
        vector<string> stack = vector<string>();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (str != "") {
                    stack.push_back(str);
                }
                str = "";
            } else {
                str += s[i];
            }
            if (i == s.length()-1 && s[i] != ' ')
                stack.push_back(str);
        }
        s = "";
        for (long i = stack.end()-stack.begin()-1; i >= 0; i--) {
            s += stack[i];
            if (i != 0) {
                s += " ";
            }
        }
    }
};
 */

/** 4ms */
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
            return;
        reverseAll(s,0,s.size()-1);//翻转整个句子
        reverseEveryWords(s);//翻转每个单词
        cleanSpace(s);//处理空格等字符使得满足题意
    }
    void reverseAll(string &s,int left,int right){
        while(left<right){
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
    void reverseEveryWords(string &s){
        int left=0;
        int right=0;
        while(left<s.size()){
            if(s[left]==' '){
                right++;
                left++;
            }else if(s[right]==' '){
                reverseAll(s,left,--right);
                right++;
                left=right;
            }else if(right==s.size()-1){
                reverseAll(s,left,right);
                left=++right;
            }
            else
                right++;
        }
    }
    void cleanSpace(string &s){
        int i=0;
        int j=0;
        while(j<s.size()){
            while (j<s.size()&&s[j]==' ') j++;
            while (j<s.size()&&s[j]!=' ') s[i++]=s[j++];
            while (j<s.size()&&s[j]==' ') j++;
            if(j<s.size())s[i++]=' ';
        }
        s=s.substr(0,i);
    }
};

int main(int argc, const char * argv[]) {
    string str = "the sky is blue";
//    string str = " 1 ";
    Solution sol = Solution();
    sol.reverseWords(str);
    cout << str << "Here" << endl;
    return 0;
}
