//
//  main.cpp
//  223. 矩形面积
//
//  Created by SeacenLiu on 2019/3/19.
//  Copyright © 2019 成. All rights reserved.
//

/**
 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 
 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 
 [Rectangle Area](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rectangle_area.png)
 
 示例:
 
 输入: -3, 0, 3, 4, 0, -1, 9, 2
 输出: 45
 说明: 假设矩形面积不会超出 int 的范围。
 */

/**
 暴力法
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long LA = A, LB = B, LC = C, LD = D, LE = E, LF = F, LG = G, LH = H;
        long totalSquar = (LD-LB)*(LC-LA) + (LH-LF)*(LG-LE);
        // A < C; E < G; B < D; F < H
        if (LH < LB || LF > LD || LG < LA || LC < LE)
            return totalSquar;
        
        long x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        if (LH > LD)
            y1 = LD;
        else
            y1 = LH;
        if (LB < LF)
            y2 = LF;
        else
            y2 = LB;
        
        long y = abs(y1-y2);
        if (LE < LA)
            x1 = LA;
        else
            x1 = LE;
        if (LC < LG)
            x2 = LC;
        else
            x2 = LG;
        long x = abs(x1-x2);
        return totalSquar - x*y;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution sol = Solution();
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
