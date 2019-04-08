//
//  main.cpp
//  304. 二维区域和检索 - 矩阵不可变
//
//  Created by SeacenLiu on 2019/4/8.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 
 Range Sum Query 2D
 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
 
 示例:
 
 给定 matrix = [
 [3, 0, 1, 4, 2],
 [5, 6, 3, 2, 1],
 [1, 2, 0, 1, 5],
 [4, 1, 0, 1, 7],
 [1, 0, 3, 0, 5]
 ]
 
 sumRegion(2, 1, 4, 3) -> 8
 sumRegion(1, 1, 2, 2) -> 11
 sumRegion(1, 2, 2, 4) -> 12
 说明:
 
 你可以假设矩阵不可变。
 会多次调用 sumRegion 方法。
 你可以假设 row1 ≤ row2 且 col1 ≤ col2。
 */

/**
 - 思路一：暴力法
    - 超时
 - 思路二：类似动态规划
    - 保存矩阵和
    - 状态：matrixSum的值表示：matrixSum[i][j] = sumRegion(i, 0, i, j)
    - 递推公式：sumRegion(r1, c1, r2, c2) = matrixSum[r1~r2][c2] - matrixSum[r1~r2][c1-1]
 */

#include <iostream>
#include <vector>
using namespace std;

/// 思路二
class NumMatrix {
private:
    vector<vector<int>> matrixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (auto nums: matrix) {
            vector<int> rowSum;
            int tempSum = 0;
            for (auto num : nums) {
                tempSum += num;
                rowSum.push_back(tempSum);
            }
            matrixSum.push_back(rowSum);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (col1 == 0) {
            for (int row = row1; row <= row2; ++row) {
                sum += matrixSum[row][col2];
            }
        } else {
            for (int row = row1; row <= row2; ++row) {
                sum += matrixSum[row][col2] - matrixSum[row][col1 - 1];
            }
        }
        return sum;
    }
};

// 思路一： 暴力法
class NumMatrix1 {
private:
    vector<vector<int>> matrix;
public:
    NumMatrix1(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    vector<int> a1 = {3, 0, 1, 4, 2};
    vector<int> a2 = {5, 6, 3, 2, 1};
    vector<int> a3 = {1, 2, 0, 1, 5};
    vector<int> a4 = {4, 1, 0, 1, 7};
    vector<int> a5 = {1, 0, 3, 0, 5};
    vector<vector<int>> a = {a1,a2,a3,a4,a5};
    NumMatrix matrix = NumMatrix(a);
    cout << matrix.sumRegion(2, 1, 4, 3) << endl; // 8
    cout << matrix.sumRegion(1, 1, 2, 2) << endl; // 11
    cout << matrix.sumRegion(1, 2, 2, 4) << endl; // 12
    return 0;
}
