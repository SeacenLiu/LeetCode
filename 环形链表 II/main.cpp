//
//  main.cpp
//  环形链表 II
//
//  Created by SeacenLiu on 2018/11/12.
//  Copyright © 2018 成. All rights reserved.
//

/**
 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 
 说明：不允许修改给定的链表。
 
 进阶：
 你是否可以不用额外空间解决此题？
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
private:
    ListNode *meetingNode(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head->next;
        ListNode *fast = slow->next;
        while (fast != nullptr && slow != nullptr) {
            if (fast == slow)
                return fast;
            slow = slow->next;
            fast = fast->next;
            if (fast && fast->next != nullptr)
                fast = fast->next;
        }
        return nullptr;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *meet = meetingNode(head);
        if (!meet)
            return nullptr;
        ListNode *p = head;
        while (p != meet) {
            p = p->next;
            meet = meet->next;
        }
        return p;
    }
};

int num = 0;

ListNode* Create(vector<int> arr) {
    ListNode *h = new ListNode(-1);
    ListNode *p = h;
    for (auto i: arr) {
        ListNode *node = new ListNode(i);
        p->next = node;
        p=p->next;
    }
    return h->next;
}

void Test(ListNode *head) {
    cout << "第" << ++num << "个测试: ";
    Solution *sol = new Solution();
    ListNode *p = sol->detectCycle(head);
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "没有环" << endl;
    }
}

int main(int argc, const char * argv[]) {
    // 1> 0
    Test(nullptr);
    // 2> 0
    ListNode *n1 = new ListNode(0);
    Test(n1);
    // 3> 0
    ListNode *n2 = new ListNode(1);
    n1->next = n2;
    Test(n1);
    // 4> 1
    ListNode *n3 = new ListNode(2);
    n2->next = n3;
    n3->next = n1;
    Test(n1);
    // 5> 1
    ListNode *n4 = new ListNode(3);
    ListNode *n5 = new ListNode(4);
    n4->next = n5;
    n5->next = n4;
    Test(n4);
    // 6> 1
    ListNode *n6 = new ListNode(5);
    ListNode *n7 = new ListNode(6);
    ListNode *n8 = new ListNode(7);
    ListNode *n9 = new ListNode(8);
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n7;
    Test(n6);
    // 7>
    ListNode *n10 = new ListNode(3);
    ListNode *n11 = new ListNode(2);
    ListNode *n12 = new ListNode(0);
    ListNode *n13 = new ListNode(-4);
    n10->next = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = n11;
    Test(n10);
    // 8>
    ListNode *h = Create({-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5});
    Test(h);
    return 0;
}
