//
//  main.cpp
//  相对名次
//
//  Created by SeacenLiu on 2018/8/1.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
 
 (注：分数越高的选手，排名越靠前。)
 
 示例 1:
 
 输入: [5, 4, 3, 2, 1]
 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 提示:
 
 N 是一个正整数并且不会超过 10000。
 所有运动员的成绩都不相同。
 */

#include <iostream>
#include <vector>
using namespace std;

bool cmp(int x, int y) {
    return x > y;
}

class Solution {
private:
    /// 整型转字符 1...
    string resultFromInt(int i) {
        if (i == 1) {
            return "Gold Medal";
        } else if (i == 2) {
            return "Silver Medal";
        } else if (i == 3) {
            return "Bronze Medal";
        } else {
            return to_string(i);
        }
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> copy = nums;
        sort(copy.begin(), copy.end(), cmp);
        vector<string> ret(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == copy[j]) {
                    ret[i] = resultFromInt(j+1);
                    break;
                }
            }
        }
        return ret;
    }
};

/**
class Solution {
private:
    /// 整型转字符 1...
    string resultFromInt(int i) {
        if (i == 1) {
            return "Gold Medal";
        } else if (i == 2) {
            return "Silver Medal";
        } else if (i == 3) {
            return "Bronze Medal";
        } else {
            return to_string(i);
        }
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> ret = {};
        string temp = "";
        int curIdx = 0;
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            curIdx = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    curIdx++;
                }
            }
            if (curIdx == maxIdx) {
                curIdx++;
            }
            if (curIdx > maxIdx) {
                maxIdx = curIdx;
            }
            ret.push_back(resultFromInt(curIdx));
        }
        return ret;
    }
};
*/

int main(int argc, const char * argv[]) {
//    [10,3,8,9,4]
    vector<int> nums = {10,3,8,9,4};
    Solution sol = Solution();
    vector<string> ret = sol.findRelativeRanks(nums);
    for (auto str: ret) {
        cout << str << endl;
    }
    cout << "complete" << endl;
    return 0;
}
