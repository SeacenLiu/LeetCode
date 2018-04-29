//
//  main.cpp
//  两数相加
//
//  Created by SeacenLiu on 2018/4/27.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 
 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 
 示例：
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
*/

// Tip:
// 考虑到输入的链表可能很长，不可以直接按着原因用long来做计算
// 需要考虑以下几个方面
// 1. 设计好数据结构，反序存储数字，如数字932存储为2 -> 3 -> 9；
// 2. 链表对应结点相加时增加前一个结点的进位，并保存下一个结点的进位；
// 3. 两个链表长度不一致时，要处理较长链表剩余的高位和进位计算的值；
// 4. 如果最高位计算时还产生进位，则还需要添加一个额外结点。


#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), *p = &head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode t11 = ListNode(9);

    ListNode t21 = ListNode(1);
    ListNode t22 = ListNode(9);
    t21.next = &t22;
    ListNode t23 = ListNode(9);
    t22.next = &t23;
    ListNode t24 = ListNode(9);
    t23.next = &t24;
    ListNode t25 = ListNode(9);
    t24.next = &t25;
    ListNode t26 = ListNode(9);
    t25.next = &t26;
    ListNode t27 = ListNode(9);
    t26.next = &t27;
    ListNode t28 = ListNode(9);
    t27.next = &t28;
    ListNode t29 = ListNode(9);
    t28.next = &t29;
    ListNode t20 = ListNode(9);
    t29.next = &t20;

    Solution s = Solution();
    ListNode *demo = s.addTwoNumbers(&t11, &t21);

    cout << demo->val << endl;
    while (demo->next) {
        cout << demo->next->val << endl;
        demo = demo->next;
    }
    return 0;
}
