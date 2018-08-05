//
//  main.cpp
//  前K个高频元素
//
//  Created by SeacenLiu on 2018/8/5.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 
 例如，
 
 给定数组 [1,1,1,2,2,3] , 和 k = 2，返回 [1,2]。
 
 注意：
 
 你可以假设给定的 k 总是合理的，1 ≤ k ≤ 数组中不相同的元素的个数。
 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> p;
        vector<int> ret;
        for (auto num: nums) {
            ++m[num];
        }
        for (auto a: m) {
            p.push({a.second, a.first});
        }
        for (int i = 0; i < k; ++i) {
            ret.push_back(p.top().second);
            p.pop();
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution sol = Solution();
    vector<int> ret = sol.topKFrequent(nums, k);
    cout << "ok" << endl;
    return 0;
}
