//
//  main.cpp
//  135. 分发糖果
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 
 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 
 每个孩子至少分配到 1 个糖果。
 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 那么这样下来，老师 至少 需要准备多少颗糖果呢？
 
 示例 1:
 
 输入: [1,0,2]
 输出: 5
 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 示例 2:
 
 输入: [1,2,2]
 输出: 4
 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 */

/**
 - candy[] 保存分配情况
 - 核心：ratings[i] < ratings[i-1] 的情况
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        vector<int> candy(ratings.size());
        int sum = 1;
        candy[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
                sum += candy[i];
            } else if (ratings[i] < ratings[i-1]) {
                candy[i] = 1;
                sum += candy[i];
                if (candy[i-1] == 1) {
                    candy[i-1] += 1;
                    ++sum;
                    for (int j = i-2; j >= 0; --j) {
                        if (ratings[j] > ratings[j+1] && candy[j] <= candy[j+1]) {
                            candy[j] += 1;
                            ++sum;
                        } else {
                            break;
                        }
                    }
                }
            } else { // ratings[i] == ratings[i-1]
                candy[i] = 1;
                sum += candy[i];
            }
        }
        return sum;
    }
};

void test(vector<int> ratings) {
    cout << "--------------------" << endl;
    Solution sol = Solution();
    for (auto v: ratings) cout << v << " ";
    cout << endl;
    cout << sol.candy(ratings) << endl;
    cout << "--------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({});
    test({1,0,2});
    test({1,2,2});
    test({1,2,87,87,87,2,1});
    //    1,2,3,1,3,2,1 => 13
    test({1,2,3,1,0});
    //    1,2,3,2,1 => 9
    test({1,6,10,8,7,3,2});
    //    1,2,5,4,3,2,1 => 18
    return 0;
}
