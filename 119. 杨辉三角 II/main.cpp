//
//  main.cpp
//  119. 杨辉三角 II
//
//  Created by SeacenLiu on 2019/11/15.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 
 在杨辉三角中，每个数是它左上方和右上方的数的和。
 
 示例:
 
 输入: 3
 输出: [1,3,3,1]
 进阶：
 
 你可以优化你的算法到 O(k) 空间复杂度吗？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/pascals-triangle-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 [1,5,10,10,5,1]
 
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 C(n,i) = n!/(i!*(n-i)!)
 第(i+1)项是第i项的(n-i)/(i+1)倍数
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        long cur = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            res[i] = (int)cur;
            cur = cur * (rowIndex-i)/(i+1);
        }
        return res;
    }
};

void test(int rowIndex) {
    cout << "=====================" << endl;
    cout << rowIndex << endl;
    vector<int> res = Solution().getRow(rowIndex);
    for (auto val: res) {
        cout << val << " ";
    }
    cout << endl;
    cout << "=====================" << endl;
}

int main(int argc, const char * argv[]) {
    test(-1);
    test(0);
    test(1);
    test(3);
    std::cout << "Hello, World!\n";
    return 0;
}
