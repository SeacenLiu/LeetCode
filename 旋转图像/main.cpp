//
//  main.cpp
//  旋转图像
//
//  Created by SeacenLiu on 2018/8/8.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个 n × n 的二维矩阵表示一个图像。
 
 将图像顺时针旋转 90 度。
 
 说明：
 
 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 
 示例 1:
 
 给定 matrix =
 [
    [1,2,3],
    [4,5,6],
    [7,8,9]
 ],
 
 原地旋转输入矩阵，使其变为:
 [
    [7,4,1],
    [8,5,2],
    [9,6,3]
 ]
 示例 2:
 
 给定 matrix =
 [
    [ 5, 1, 9,11],
    [ 2, 4, 8,10],
    [13, 3, 6, 7],
    [15,14,12,16]
 ],
 
 原地旋转输入矩阵，使其变为:
 [
    [15,13, 2, 5],
    [14, 3, 4, 1],
    [12, 6, 8, 9],
    [16, 7,10,11]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

// 对于当前位置，计算旋转后的新位置，
// 然后再计算下一个新位置，第四个位置又变成当前位置了，
// 所以这个方法每次循环换四个数字
/**
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n-1-i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
 */

// 首先以从对角线为轴翻转，
// 然后再以x轴中线上下翻转即可得到结果
/**
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};
 */

// 这种方法首先对原数组取其转置矩阵，
// 然后把每行的数字翻转可得到结果
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,5,6};
    vector<int> nums3 = {7,8,9};
    vector<vector<int>> matrix = {nums1, nums2, nums3};
    Solution sol = Solution();
    sol.rotate(matrix);
    
    for (auto nums: matrix) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}

