//
//  main.cpp
//  11. 盛最多水的容器
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 
 说明：你不能倾斜容器，且 n 的值至少为 2。
 
 [例子](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)
 
 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 
 示例:
 
 输入: [1,8,6,2,5,4,8,3,7]
 输出: 49
 */

/**
 - 长：下标相减
 - 高：取较小值
 - 思路一：O(n^2)逐个比较
 - 思路二：贪心一波
    - 选相隔最远的
    - 选更高的
    - 距离减小，替换高度较小有可能使面积增大，替换较大的没有可能
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = (int)height.size()-1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j-i));
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return res;
    }
};

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int res = 0, tmp;
        for (int i = 0; i < height.size()-1; ++i) {
            for (int j = i+1; j < height.size(); ++j) {
                tmp = min(height[i], height[j]) * (j-i);
                res = max(res, tmp);
            }
        }
        return res;
    }
};

void test(vector<int> height) {
    Solution sol = Solution();
    cout << sol.maxArea(height) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({1,8,6,2,5,4,8,3,7});
    test({1,8});
    return 0;
}
