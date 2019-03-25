//
//  main.cpp
//  85. 最大矩形
//
//  Created by SeacenLiu on 2019/3/22.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 
 示例:
 
 输入:
 [
 ["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
 ]
 输出: 6
 */

/**
 - s = height * (rigth - left)
 - 从第一行开始扫描
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> height(n, 0); // 矩形高度
        vector<int> left(n, 0); // 宽度的左坐标
        vector<int> right(n, 0); // 宽度的右坐标
        int result = 0;
        for (int i = 0; i < m; ++i){
            // 从上只下
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            // 从左到右
            for (int j = 0; j < n; ++j){
                int k = j - 1;
                while (k >= 0 && height[j] <= height[k])
                    k = left[k] - 1;
                left[j] = k + 1;
            }
            // 从右到左
            for (int j = n - 1; j >= 0; --j) {
                int k = j + 1;
                while (k < n && height[j] <= height[k])
                    k = right[k] + 1;
                right[j] = k - 1;
            }
            
            for (int j = 0; j < n; ++j)
                result = max(result, height[j] * (right[j] - left[j] + 1));
            
        }
        return result;
    }
};


void test(vector<vector<char>> matrix) {
    cout << "--------------------" << endl;
    Solution sol = Solution();
    cout << sol.maximalRectangle(matrix) << endl;
    cout << "--------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<char> a1 = {'1','0','1','0','0'};
    vector<char> a2 = {'1','0','1','1','1'};
    vector<char> a3 = {'1','1','1','1','1'};
    vector<char> a4 = {'1','0','0','1','0'};
    test({a1, a2, a3, a4});
    return 0;
}
