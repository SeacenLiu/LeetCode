//
//  main.cpp
//  删除与获得点数
//
//  Created by SeacenLiu on 2018/5/7.
//  Copyright © 2018年 成. All rights reserved.
//

// 740
/**
 给定一个整数数组 nums ，你可以对它进行一些操作。
 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 和 nums[i] + 1 的元素。
 开始你拥有 0 个点数。返回你能通过这些操作获得的`最大点数`。
 
 示例 1:
 输入: nums = [3, 4, 2]
 输出: 6
 解释:
 删除 4 来获得 4 个点数，因此 3 也被删除。
 之后，删除 2 来获得 2 个点数。总共获得 6 个点数。
 示例 2:
 
 示例 2:
 输入: nums = [2, 2, 3, 3, 3, 4]
 输出: 9
 解释:
 删除 3 来获得 3 个点数，接着要删除两个 2 和 4 。
 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 总共获得 9 个点数。
 
 注意:
 nums的长度最大为20000。
 每个整数nums[i]的大小都在[1, 10000]范围内。
 */

/**
 给一个数组，按照规则：取一个数n累加，同时n的左右(n-1和n+1)删除；
 求累加数的最大值。很容易想到的是，如果取了一个数n，那么等于n的数也要取上才有可能得到最大。
 所以先用map将同数值的数先累加，键为数值，值为同数值的总值。
 然后用动态规划的思想，用两个数值max1和max2，分别代表取当前的数和不取当前的数得到的最大和。
 如果取当前的数，则要看前一个数是不是邻近的数，
 如果是，则max1更新为原max2加上当前数的总值（也就是不用前一个数）；
 如果不是，则max1更新为max1和max2的最大值加上当前数的总值。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        sort(nums.begin(), nums.end());
        for(auto n:nums) {
            m[n] += n;
        }
        int max1 = 0, max2 = 0;
        map<int, int>::iterator p;
        for(auto i = m.begin(); i != m.end(); ++i) {
            if(i == m.begin()) {
                max1 = i->second;
                max2 = 0;
            }
            else {
                int pmax1 = max1, pmax2 = max2;
                max2 = max(pmax1, pmax2);
                if(i->first == p->first+1) {
                    max1 = pmax2 + i->second;
                }
                else {
                    max1 = max2 + i->second;
                }
            }
            p = i;
        }
        return max(max1, max2);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a = vector<int>();

//    a.push_back(3);
//    a.push_back(1);
    
//    a.push_back(2);
//    a.push_back(4);
//    a.push_back(3);
    
//    a.push_back(2);
//    a.push_back(2);
//    a.push_back(3);
//    a.push_back(3);
//    a.push_back(3);
//    a.push_back(4);
    
    a.push_back(8);
    a.push_back(10);
    a.push_back(4);
    a.push_back(9);
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(9);
    a.push_back(4);
    a.push_back(10);
    
    Solution sol = Solution();
    cout << sol.deleteAndEarn(a) << endl;
    return 0;
}
