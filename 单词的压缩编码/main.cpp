//
//  main.cpp
//  单词的压缩编码
//
//  Created by SeacenLiu on 2018/10/22.
//  Copyright © 2018 成. All rights reserved.
//

/*
 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 
 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
 
 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
 
 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 
 示例：
 
 输入: words = ["time", "me", "bell"]
 输出: 10
 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 
 
 提示：
 
 1 <= words.length <= 2000
 1 <= words[i].length <= 7
 每个单词都是小写字母 。
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 判断子串问题
 
 将words放进集合中
 再一个个看他的子串（开头不确定，结尾一定是最后）是否在集合中，有就移除掉
 */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.size() == 0) return 0;
        unordered_set<string> set(words.begin(), words.end());
        for (auto w: set)
            for (int i = 1; i < w.size(); i++)
                set.erase(w.substr(i));
        int res = 0;
        for (auto w: set)
            res += w.size() + 1;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<string> words = {"time", "me", "bell"};
    cout << sol.minimumLengthEncoding(words) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
