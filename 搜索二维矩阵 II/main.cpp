//
//  main.cpp
//  搜索二维矩阵 II
//
//  Created by SeacenLiu on 2018/10/16.
//  Copyright © 2018 成. All rights reserved.
//

/*
 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 
 每行的元素从左到右升序排列。
 每列的元素从上到下升序排列。
 示例:
 
 现有矩阵 matrix 如下：
 
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 给定 target = 5，返回 true。
 
 给定 target = 20，返回 false。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int rowCount = (int)matrix.size();
        int colCount = (int)matrix[0].size();
        int row = 0;
        int col = colCount-1;
        int value = 0;
        while (row < rowCount && col >= 0) {
            value = matrix[row][col];
            if (target > value) {
                row++;
            } else if (target < value) {
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> a1 = {1,   4,  7, 11, 15};
    vector<int> a2 = {2,   5,  8, 12, 19};
    vector<int> a3 = {3,   6,  9, 16, 22};
    vector<int> a4 = {10, 13, 14, 17, 24};
    vector<int> a5 = {18, 21, 23, 26, 30};
    vector<vector<int>> a = {a1, a2, a3, a4, a5};
    
    Solution sol = Solution();
    cout << sol.searchMatrix(a, 5) << endl;
    cout << sol.searchMatrix(a, 20) << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
