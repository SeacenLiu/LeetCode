//
//  main.cpp
//  对角线遍历
//
//  Created by SeacenLiu on 2018/10/19.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 
 示例:
 
 输入:
 [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
 ]
 
 输出:  [1,2,4,7,5,3,6,8,9]
 
 解释:
 
 
 
 说明:
 
 给定矩阵中的元素总数不会超过 100000 。
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ],
 [10,11,12 ]
 ]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int maxX = (int)matrix[0].size();
        int maxY = (int)matrix.size();
        int x = 0, y = 0;
        vector<int> res(maxX*maxY);
        for (int i = 0; i < maxX*maxY; i++) {
            res[i] = matrix[y][x];
            if ((y + x) % 2 == 0) {
                if (x == maxX - 1) {++y;}
                else if (y == 0) {++x;}
                else {--y; ++x;}
            } else {
                if (y == maxY - 1) {++x;}
                else if (x == 0) {++y;}
                else {++y; --x;}
            }
        }
        return res;
    }
};

void PrintVector(vector<int> arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << arr[i];
        if (i < arr.size()-1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    PrintVector(sol.findDiagonalOrder(a));
    std::cout << "Hello, World!\n";
    return 0;
}
