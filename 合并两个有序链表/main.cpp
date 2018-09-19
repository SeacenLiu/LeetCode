//
//  main.cpp
//  合并两个有序链表
//
//  Created by SeacenLiu on 2018/9/18.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
 示例：
 
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        ListNode *mergeNode = nullptr;
        
        if (l1->val < l2->val) {
            mergeNode = l1;
            mergeNode->next = mergeTwoLists(l1->next, l2);
        } else {
            mergeNode = l2;
            mergeNode->next = mergeTwoLists(l1, l2->next);
        }
        
        return mergeNode;
    }
};

/** 8ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        
        ListNode *p = new ListNode(0);
        ListNode *h = p;
        
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *n = nullptr;
            if (l1->val < l2->val) {
                n = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                n = new ListNode(l2->val);
                l2 = l2->next;
            }
            p->next = n;
            p = p->next;
        }
        
        if (l1 != nullptr) {
            p->next = l1;
        } else if (l2 != nullptr) {
            p->next = l2;
        }
        
        return h->next;
    }
};
 */

/** 32ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *ph = new ListNode(0);
        ListNode *p = ph;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val || l1->val == l2->val) {
                    ListNode *node = new ListNode(l1->val);
                    ph->next = node;
                    ph = ph->next;
                    l1 = l1->next;
                } else {
                    ListNode *node = new ListNode(l2->val);
                    ph->next = node;
                    ph = ph->next;
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                ListNode *node = new ListNode(l1->val);
                ph->next = node;
                ph = ph->next;
                l1 = l1->next;
            } else if (l2 != nullptr) {
                ListNode *node = new ListNode(l2->val);
                ph->next = node;
                ph = ph->next;
                l2 = l2->next;
            }
        }

        return p->next;
    }
};
*/

void PrintList(ListNode *h) {
    while (h != nullptr) {
        std::cout << h->val << " ";
        h = h -> next;
    }
    std::cout << std::endl;
}

ListNode* CreateNode(int a[],int length) {
    ListNode* n = new ListNode(0);
    ListNode* h = n;
    for (int i = 0; i < length; i++) {
        ListNode *node = new ListNode(a[i]);
        n->next = node;
        n = node;
    }
    return h->next;
}

int main(int argc, const char * argv[]) {
    Solution *sol = new Solution();
    int a1[3] = {1, 2, 4};
    ListNode *l1 = CreateNode(a1, 3);
    int a2[3] = {1, 3, 4};
    ListNode *l2 = CreateNode(a2, 3);
    PrintList(l1);
    PrintList(l2);
    PrintList(sol->mergeTwoLists(l1, l2));
    std::cout << "Hello, World!\n";
    return 0;
}
