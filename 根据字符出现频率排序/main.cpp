//
//  main.cpp
//  根据字符出现频率排序
//
//  Created by SeacenLiu on 2018/8/9.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
 
 示例 1:
 
 输入:
 "tree"
 
 输出:
 "eert"
 
 解释:
 'e'出现两次，'r'和't'都只出现一次。
 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
 示例 2:
 
 输入:
 "cccaaa"
 
 输出:
 "cccaaa"
 
 解释:
 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
 示例 3:
 
 输入:
 "Aabb"
 
 输出:
 "bbAa"
 
 解释:
 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
 注意'A'和'a'被认为是两种不同的字符。
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        string ret = "";
        pair<int, char> temp;
        for (auto ch: s) {
            ++m[ch];
        }
        for (auto a: m) {
            q.push({a.second, a.first});
        }
        for (int i = 0; i < m.size(); i++) {
            temp = q.top();
            q.pop();
            for (int j = 0; j < temp.first; j++) {
                ret += temp.second;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string s = "Aabb";
    Solution sol = Solution();
    string ret = sol.frequencySort(s);
    cout << ret << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
