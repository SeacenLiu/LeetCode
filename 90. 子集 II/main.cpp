//
//  main.cpp
//  90. 子集 II
//
//  Created by SeacenLiu on 2019/4/1.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 
 说明：解集不能包含重复的子集。
 
 示例:
 
 输入: [1,2,2]
 输出:
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */

/**
 - 回溯：
    - 需要先排序
    - 再全排列
 - 遍历
    - 先进行排序，保证重复元素挨在一起
    - 记录每次遍历生成的新序列的长度，这里用left表示每次遍历的开始位置，right结束位置，len表示长度
    - 根据与前面元素是否重复，来决定left的取值，也就是开始遍历的位置
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        int left = 0, right = 1, len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && (nums[i] == nums[i-1]))
                left = (int)ans.size() - len;
            else
                left = 0;
            right = (int)ans.size();
            len = right - left;
            for (int j = left; j < right; ++j) {
                v = ans[j];
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};


class Solution1 {
private:
    vector<vector<int>> res;
    void f(int idx, vector<int> cur, vector<int>& nums) {
        if (idx > nums.size())
            return;
        res.push_back(cur);
        for (int i = idx; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            f(i+1, cur, nums);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        f(0, cur, nums);
        set<vector<int>> set(res.begin(),res.end());
        res.assign(set.begin(), set.end());
        return res;
    }
};

void test(vector<int> a) {
    cout << "--------------------" << endl;
    for (auto v: a) cout << v << " ";
    cout << endl;
    Solution sol = Solution();
    vector<vector<int>> res = sol.subsetsWithDup(a);
    for (auto arr: res) {
        for (auto v: arr) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({1,2,2}); // [[],[2],[2,2],[1],[1,2],[1,2,2]]
    test({4,4,4,1,4}); // [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
    // [[],[1],[1,4],[4],[4,1],[4,1,4],[4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,1],[4,4,4,1,4],[4,4,4,4]]
    return 0;
}
