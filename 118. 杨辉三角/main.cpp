//
//  main.cpp
//  118. 杨辉三角
//
//  Created by SeacenLiu on 2019/11/15.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

 ![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

 在杨辉三角中，每个数是它左上方和右上方的数的和。

 示例:

 输入: 5
 输出:
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/pascals-triangle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i+1, 0);
            for (int j = 0; j < i+1; ++j) {
                if (j == 0 || j == i) {
                    tmp[j] = 1;
                    continue;
                }
                tmp[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};

void test(int numRows) {
    cout << "==========================" << endl;
    cout << numRows << endl;
    vector<vector<int>> res = Solution().generate(numRows);
    for (auto level: res) {
        for (auto val: level) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "==========================" << endl;
}

int main(int argc, const char * argv[]) {
    test(-1);
    test(0);
    test(1);
    test(5);
    std::cout << "Hello, World!\n";
    return 0;
}
