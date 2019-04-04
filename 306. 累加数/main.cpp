//
//  main.cpp
//  306. 累加数
//
//  Created by SeacenLiu on 2019/4/4.
//  Copyright © 2019 成. All rights reserved.
//

/**
 累加数是一个字符串，组成它的数字可以形成累加序列。
 
 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
 
 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
 
 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 
 示例 1:
 
 输入: "112358"
 输出: true
 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 示例 2:
 
 输入: "199100199"
 输出: true
 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 进阶:
 你如何处理一个溢出的过大的整数输入?
 */

/**
 - 剪枝上需要下功夫!!!
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 并没有提升多少...
class Solution {
private:
    bool isValue(string num) {
        if (num.empty() || (num[0] == '0' && num.size() > 1))
            return false;
        return true;
    }
    string add(string a, string b) {
        if (a.length() > b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        if (a == "0")
            return b;
        int n = (int)b.length()+1;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res(n, '0');
        int carry = 0, i = 0;
        for (; i < a.length(); ++i) {
            int value = (a[i]-'0') + (b[i]-'0') + carry;
            carry = value / 10;
            res[i] = (value%10) + '0';
        }
        for (; i < b.length();  ++i) {
            int value = (b[i]-'0') + carry;
            carry = value / 10;
            res[i] = (value%10) + '0';
        }
        res[i] = carry + '0';
        reverse(res.begin(), res.end());
        return res.substr(res.find_first_not_of('0'));
    }
    int compare(string a, string b) {
        if (a.length() > b.length())
            return 1;
        if (a.length() < b.length())
            return -1;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] > b[i])
                return 1;
            if (a[i] < b[i])
                return -1;
        }
        return 0;
    }
    int check(vector<string> cur, string b) {
        if (cur.size() < 2)
            return 0;
        string sum = add(cur[cur.size()-2], cur[cur.size()-1]);
        return compare(sum, b);
    }
    void f(int pos, string pre, string curSum, int cnt, string num, bool& res) {
        if (res)
            return;
        if (pos == num.length()) {
            if (cnt >= 3)
                res = true;
            return;
        }
        for (int i = pos; i < num.length(); ++i) {
            if (cnt < 2 && i-pos+1 > num.length()/2)
                break;
            string sub = num.substr(pos, i-pos+1);
            if (!isValue(sub))
                break;
            if (pre.empty()) {
                f(i+1, sub, curSum, cnt+1, num, res);
            } else if (curSum.empty()) {
                string newSum = add(pre, sub);
                f(i+1, sub, newSum, cnt+1, num, res);
            } else {
                int flag = compare(curSum, sub);
                if (flag == 0) {
                    string newSum = add(pre, sub);
                    f(i+1, sub, newSum, cnt+1, num, res);
                }
            }
        }
    }
public:
    bool isAdditiveNumber(string num) {
        bool res = false;
        vector<string> tmp;
        f(0, "", "", 0, num, res);
        return res;
    }
};

// 初版
class Solution1 {
private:
    bool isValue(string num) {
        if (num.empty() || (num[0] == '0' && num.size() > 1))
            return false;
        return true;
    }
    string add(string a, string b) {
        if (a.length() > b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        if (a == "0")
            return b;
        int n = (int)b.length()+1;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res(n, '0');
        int carry = 0, i = 0;
        for (; i < a.length(); ++i) {
            int value = (a[i]-'0') + (b[i]-'0') + carry;
            carry = value / 10;
            res[i] = (value%10) + '0';
        }
        for (; i < b.length();  ++i) {
            int value = (b[i]-'0') + carry;
            carry = value / 10;
            res[i] = (value%10) + '0';
        }
        res[i] = carry + '0';
        reverse(res.begin(), res.end());
        return res.substr(res.find_first_not_of('0'));
    }
    int compare(string a, string b) {
        if (a.length() > b.length())
            return 1;
        if (a.length() < b.length())
            return -1;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] > b[i])
                return 1;
            if (a[i] < b[i])
                return -1;
        }
        return 0;
    }
    int check(vector<string> cur, string b) {
        if (cur.size() < 2)
            return 0;
        string sum = add(cur[cur.size()-2], cur[cur.size()-1]);
        return compare(sum, b);
    }
    void f(int pos, vector<string>& cur, string num, bool& res) {
        if (res)
            return;
        if (pos == num.length()) {
            if (cur.size() >= 3)
                res = true;
            return;
        }
        for (int i = pos; i < num.length(); ++i) {
            if (cur.size() < 2 && i-pos+1 > num.length()/2)
                break;
            string sub = num.substr(pos, i-pos+1);
            if (!isValue(sub))
                break;
            int flag = check(cur, sub);
            if (flag == 0) {
                cur.push_back(sub);
                f(i+1, cur, num, res);
                cur.pop_back();
            } else if (flag < 0) {
                break;
            }
        }
    }
public:
    bool isAdditiveNumber(string num) {
        bool res = false;
        vector<string> tmp;
        f(0, tmp, num, res);
        return res;
    }
};

void test(string num) {
    cout << "--------------------" << endl;
    Solution sol = Solution();
    cout << num << endl;
    cout << sol.isAdditiveNumber(num) << endl;
    cout << "--------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test("");
    test("000");
    test("112358");
    test("199100199");
    test("198019823962");
    test("199111992");
    test("1991000199299498797");
    return 0;
}
