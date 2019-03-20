//
//  main.cpp
//  213. 打家劫舍 II
//
//  Created by SeacenLiu on 2019/3/20.
//  Copyright © 2019 成. All rights reserved.
//

/**
 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 
 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 
 示例 1:
 
 输入: [2,3,2]
 输出: 3
 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 示例 2:
 
 输入: [1,2,3,1]
 输出: 4
 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 偷窃到的最高金额 = 1 + 3 = 4 。
 */

/**
 - 两次动态规划
 - 数组表示，偷到每一家的最大情况
 - dp1[i] = max(dp1[i-2], dp1[i-3]) + nums[i];
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp1(nums.begin(), nums.end());
        if (n >= 3) {
            dp1[2] += dp1[0];
            for (int i = 3; i < n; ++i) {
                dp1[i] = max(dp1[i-2], dp1[i-3]) + nums[i];
            }
        }
        int result_1 = 0;
        for (int i = 0; i < n-1; ++i) {
            result_1 = max(result_1, dp1[i]);
        }
        
        vector<int> dp2(nums.begin(), nums.end());
        if (n >= 4) {
            dp2[3] += dp2[1];
            for (int i = 4; i < n; ++i) {
                dp2[i] = max(dp2[i-2], dp2[i-3]) + nums[i];
            }
        }
        int result_2 = 0;
        for (int i = 0; i < n; ++i) {
            result_2 = max(result_2, dp2[i]);
        }
        
        return max(result_1, result_2);
    }
};

void test(vector<int> nums) {
    Solution sol = Solution();
    cout << sol.rob(nums) << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({});
    test({2,3,2}); // 3
    test({1,2,3,1}); // 4
    test({2,7,9,3,1}); // 11
    return 0;
}


//=================================================================
//==30==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000007c at pc 0x00000040675b bp 0x7ffdac120da0 sp 0x7ffdac120d98
//READ of size 4 at 0x60200000007c thread T0
//#1 0x7fde664cc2e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
//
//0x60200000007c is located 0 bytes to the right of 12-byte region [0x602000000070,0x60200000007c)
//                                                                  allocated by thread T0 here:
//#0 0x7fde67ef1ce0 in operator new(unsigned long) (/usr/local/lib64/libasan.so.5+0xe9ce0)
//#2 0x7fde664cc2e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
//
//                                                                  Shadow bytes around the buggy address:
//                                                                  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//                                                                  =>0x0c047fff8000: fa fa fd fd fa fa 00 04 fa fa 00 04 fa fa 00[04]
//                                                                  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//                                                                  Shadow byte legend (one shadow byte represents 8 application bytes):
//                                                                  Addressable:           00
//                                                                  Partially addressable: 01 02 03 04 05 06 07
//                                                                  Heap left redzone:       fa
//                                                                  Freed heap region:       fd
//                                                                  Stack left redzone:      f1
//                                                                  Stack mid redzone:       f2
//                                                                  Stack right redzone:     f3
//                                                                  Stack after return:      f5
//                                                                  Stack use after scope:   f8
//                                                                  Global redzone:          f9
//                                                                  Global init order:       f6
//                                                                  Poisoned by user:        f7
//                                                                  Container overflow:      fc
//                                                                  Array cookie:            ac
//                                                                  Intra object redzone:    bb
//                                                                  ASan internal:           fe
//                                                                  Left alloca redzone:     ca
//                                                                  Right alloca redzone:    cb
//                                                                  ==30==ABORTING
//                                                                  最后执行的输入：
//                                                                  [2,3,2]
//                                                                  提交时间    状态    执行用时    内存消耗    语言
//                                                                  几秒前    执行出错    N/A    N/A    cpp
//                                                                  5 小时前    解答错误    N/A    N/A    cpp
//                                                                  5 小时前    解答错误    N/A    N/A    cpp
//                                                                  5 小时前    解答错误    N/A    N/A    cpp
//                                                                  5 小时前    解答错误    N/A    N/A    cpp
//
//                                                                  题目列表
//
//                                                                  随机一题
//
//                                                                  上一题
//                                                                  205/844
//
//                                                                  下一题
//
//
//
//
//
//
