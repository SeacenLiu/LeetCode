//
//  main.cpp
//  为运算表达式设计优先级
//
//  Created by SeacenLiu on 2018/10/18.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
 
 示例 1:
 
 输入: "2-1-1"
 输出: [0, 2]
 解释:
 ((2-1)-1) = 0
 (2-(1-1)) = 2
 示例 2:
 
 输入: "2*3-4*5"
 输出: [-34, -14, -10, -10, 10]
 解释:
 (2*(3-(4*5))) = -34
 ((2*3)-(4*5)) = -14
 ((2*(3-4))*5) = -10
 (2*((3-4)*5)) = -10
 (((2*3)-4)*5) = 10
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 1.按照运算符做分割，然后用分治算法解。
 2.边界条件为：如果剩下的的字符串中没有运算符，即剩下的字符串中有且仅有数字。
 */

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        //边界条件是如果找不到运算符，说明只有
        for(int i=0;i<input.size();i++)
        {
            char c = input[i];
            if(c=='+'||c=='-'||c=='*')
            {
                auto res1 = diffWaysToCompute(input.substr(0,i));
                auto res2 = diffWaysToCompute(input.substr(i+1));
                for(int r1:res1)
                    for(int r2:res2)
                    {
                        if(c=='+')
                            res.push_back(r1+r2);
                        if(c=='-')
                            res.push_back(r1-r2);
                        if(c=='*')
                            res.push_back(r1*r2);
                    }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));

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
    PrintVector(sol.diffWaysToCompute("2-1-1"));
    PrintVector(sol.diffWaysToCompute("2*3-4*5"));
    std::cout << "Hello, World!\n";
    return 0;
}
