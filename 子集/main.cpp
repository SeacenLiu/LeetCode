//
//  main.cpp
//  子集
//
//  Created by SeacenLiu on 2018/7/27.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 
 说明：解集不能包含重复的子集。
 
 示例:
 
 输入: nums = [1,2,3]
 输出:
 [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
 ]
 */

// [1,2,3]
// [[],[3],[2],[2,3],[1],[1,3],[1,2],[1,2,3]]

// 当前选中的 和未选中的 逐个合并

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums,vector<int> &cur,int index,int total){
        if(cur.size()==total){
            ans.push_back(cur);
            return;
        }
        int len = (int)nums.size();
        for(int i = index;i<len;++i){
            cur.push_back(nums[i]);
            backtrack(nums, cur, i+1, total);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = (int)nums.size();
        for(int i = 0;i<=len;++i){
            vector<int> cur;
            backtrack(nums,cur, 0, i);
        }
        return ans;
    }
};

/**
/// 4ms
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int len = (int)nums.size();
        int set_num = 1 << len;
        vector<vector<int>> res;
        vector<int> t;
        for(int i = 0;i < set_num;i++)
        {
            t.clear();
            int idx = 0;
            for(int tmp = i;tmp > 0;tmp >>= 1)
            {
                if((tmp & 1) == 1)
                    t.push_back(nums[idx]);
                idx ++;
            }
            res.push_back(t);
        }
        return res;
    }
};
*/

/**
class Solution {
private:
    void dfsHelper(int startIndex,
                   vector<int> & currSet,
                   vector<int> & nums,
                   vector<vector<int>> & result) {
        // add current set to result
        result.push_back(currSet);
        
        // traverse all neighbor nodes
        // use startIndex to avoid
        // going back to previous nums
        for (int i = startIndex; i < nums.size(); ++i) {
            // add something
            currSet.push_back(nums[i]);
            
            // recursive call
            dfsHelper(i+1, currSet, nums, result);
            
            // remove something
            currSet.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0)
            return result;
        
        // first sort the nums
        sort(nums.begin(), nums.end());
        
        vector<int> subset;
        dfsHelper(0, subset, nums, result);
        return result;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1, 2, 3};
    
    Solution sol = Solution();
    vector<vector<int>> ret = sol.subsets(nums);
    
    for (auto sub: ret) {
        cout << "---" << endl;
        for (auto element: sub) {
            cout << element << endl;
        }
        cout << "---" << endl;
    }
    
    return 0;
}
