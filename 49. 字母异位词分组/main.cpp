//
//  main.cpp
//  49. 字母异位词分组
//
//  Created by SeacenLiu on 2019/11/25.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 示例:

 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 输出:
 [
   ["ate","eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]
 说明：

 所有输入均为小写字母。
 不考虑答案输出的顺序。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/group-anagrams
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 方法一: 全部单词都排序，直接判断是否相同
 时间复杂度: O(NKlogK), N 是 strs 的长度, K 是 strs 中字符的最大长度。(遍历 + 排序)
 空间复杂度: O(NK)
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> dict;
        string tmp;
        for (int i = 0; i < strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (dict.find(tmp) == dict.end()) {
                dict[tmp] = (int)res.size();
                res.push_back({strs[i]});
            } else {
                res[dict[tmp]].push_back(strs[i]);
            }
        }
        return res;
    }
};

/**
 class Solution {
 public:
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
         
         return {};
     }
 };
 */

void test(vector<string> strs) {
    cout << "===========================" << endl;
    for (auto val: strs)
        cout << val << " ";
    cout << endl;
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    for (auto arr: res) {
        for (auto val: arr)
            cout << val << " ";
        cout << endl;
    }
    cout << "===========================" << endl;
}

int main(int argc, const char * argv[]) {
    test({});
    test({"aa"});
    test({"eat", "tea", "tan", "ate", "nat", "bat"});
    std::cout << "Hello, World!\n";
    return 0;
}
