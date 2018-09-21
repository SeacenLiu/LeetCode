//
//  main.cpp
//  螺旋矩阵 II
//
//  Created by SeacenLiu on 2018/9/21.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的`正方形`矩阵。
 
 示例:
 
 输入: 3
 输出:
 [
    [ 1, 2, 3 ],
    [ 8, 9, 4 ],
    [ 7, 6, 5 ]
 ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ret = {};
    int num = 1;
    void fixMatrix(int row, int col, int start) {
        int endX = col - 1 - start;
        int endY = row - 1- start;
        
        for (int i = start; i <= endX; ++i)
            ret[start][i] = num++;
        
        if (start < endY)
            for (int i = start + 1; i <= endY; ++i)
                ret[i][endX] = num++;
        
        if (start < endX && start < endY)
            for (int i = endX - 1; i >= start; --i)
                ret[endY][i] = num++;
        
        if (start < endX && start < endY - 1)
            for (int i = endY - 1; i >= start + 1; --i)
                ret[i][start] = num++;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        ret = {};
        if (n <= 0) return ret;
        int row = n;
        int col = n;
        int start = 0;
        vector<int> line = {};
        for (int i = 0; i < n ; i++)
            line.push_back(0);
        for (int i = 0; i < n ; i++)
            ret.push_back(line);
        while (row > 2 * start && col > 2 * start) {
            fixMatrix(row, col, start);
            start++;
        }
        return ret;
    }
};

void PrintVector(vector<vector<int>> arr) {
    for (auto i: arr) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "-------------" << endl;
}

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    for (int i = 0; i < 10; i++) {
        PrintVector(sol.generateMatrix(i));
    }
    std::cout << "Hello, World!\n";
    return 0;
}

/** 思路
 获取 1 ~ n^2
 
 [1]
 
 [ 1, 2]
 [ 4, 3]
 
 [ 1, 2, 3 ]
 [ 8, 9, 4 ]
 [ 7, 6, 5 ]
 
 [  1,  2,  3, 4]
 [ 12, 13, 14, 5]
 [ 11, 16, 15, 6]
 [ 10,  9,  8, 7]
 
 [  1,  2,  3,  4, 5]
 [ 16, 17, 18, 19, 6]
 [ 15, 24, 25, 20, 7]
 [ 14, 23, 22, 21, 8]
 [ 13, 12, 11, 10, 9]
 
 1  1*1   1  1
 2  2*2   4  4
 3  3*3   9  9
 4  4*4  16  16
 5  5*5  25  25
 
 // 类似 旋转矩阵 逐个添加
 */
