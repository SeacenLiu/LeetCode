//
//  main.cpp
//  344. 反转字符串
//
//  Created by SeacenLiu on 2019/11/19.
//  Copyright © 2019 成. All rights reserved.
//

/**
 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 示例 1：

 输入：["h","e","l","l","o"]
 输出：["o","l","l","e","h"]
 示例 2：

 输入：["H","a","n","n","a","h"]
 输出：["h","a","n","n","a","H"]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

// 方法二: 双指针
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size()>0) {
            vector<char>::iterator p;
            vector<char>::iterator q;
            p = s.begin();
            q = s.end()-1;
            while (p < q) {
                char tmp = *p;
                *p = *q;
                *q = tmp;
                p++;
                q--;
            }
        }
    }
};

// 方法一: 单向交换
class Solution1 {
public:
    void reverseString(vector<char>& s) {
        int length = (int)s.size();
        for (int i = 0; i < length >> 1; ++i) {
            swap(s[i], s[length-i-1]);
        }
    }
};

void test(vector<char> s, vector<char> ans) {
    cout << "==========================" << endl;
    for (char ch: s)
        cout << ch << " ";
    cout << endl;
    for (char ch: ans)
        cout << ch << " ";
    cout << endl;
    Solution().reverseString(s);
    for (char ch: s)
        cout << ch << " ";
    cout << endl;
    cout << "==========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({'h','e','l','l','o'}, {'o','l','l','e','h'});
    test({'H','a','n','n','a','h'}, {'h','a','n','n','a','H'});
    std::cout << "Hello, World!\n";
    return 0;
}
