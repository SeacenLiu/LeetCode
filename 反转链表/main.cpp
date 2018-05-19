//
//  main.cpp
//  反转链表
//
//  Created by SeacenLiu on 2018/5/19.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 反转一个单链表。
 
 示例:
 
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 进阶:
 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *newHead = NULL, *tmp = NULL;
        ListNode *cur = head;
        while (cur) {
            tmp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur=tmp;
        }
        return newHead;
    }
};

/** 使用栈 8ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        vector<ListNode*> stack;
        while (head) {
            stack.push_back(head);
            head = head->next;
        }
        head = stack[stack.end()-stack.begin()-1];
        ListNode *previous = NULL;
        ListNode *current = NULL;
        while (!stack.empty()) {
            current = stack[stack.end()-stack.begin()-1];
            stack.pop_back();
            if (previous) {
                previous->next = current;
            }
            previous = current;
        }
        previous->next = NULL;
        return head;
    }
};
 */

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Solution sol = Solution();
    ListNode *pHead = sol.reverseList(node1);
    while (pHead) {
        cout << pHead -> val << endl;
        pHead = pHead -> next;
    }
    return 0;
}
