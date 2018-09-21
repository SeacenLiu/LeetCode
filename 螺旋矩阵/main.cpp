//
//  main.cpp
//  螺旋矩阵
//
//  Created by SeacenLiu on 2018/9/21.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 
 示例 1:
 
 输入:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 输出: [1,2,3,6,9,8,7,4,5]
 示例 2:
 
 输入:
 [
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
 ]
 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ret = {};
    void printMatrixInCircle(vector<vector<int>> matrix, int column, int row, int start) {
        int endX = column - 1 - start;
        int endY = row - 1- start;
        
        // 从左到右
        for (int i = start; i <= endX; ++i)
            ret.push_back(matrix[start][i]);
        
        // 从上到下
        if (start < endY)
            for (int i = start + 1; i <= endY; ++i)
                ret.push_back(matrix[i][endX]);
        
        // 从右到左
        if (start < endX && start < endY)
            for (int i = endX - 1; i >= start; --i)
                ret.push_back(matrix[endY][i]);
        
        // 从下到上
        if (start < endX && start < endY - 1)
            for (int i = endY - 1; i >= start + 1; --i)
                ret.push_back(matrix[i][start]);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int rowCount = (int)matrix.size();
        int columnCount = (int)matrix[0].size();
        int start = 0;
        while (columnCount > start * 2 && rowCount > start * 2) {
            printMatrixInCircle(matrix, columnCount, rowCount, start);
            start++;
        }
        return ret;
    }
};

void PrintVector(vector<int> arr) {
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> input = {{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
    Solution sol = Solution();
    PrintVector(sol.spiralOrder(input));
    std::cout << "Hello, World!\n";
    return 0;
}
