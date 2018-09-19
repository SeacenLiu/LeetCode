//
//  main.cpp
//  删除链表的倒数第N个节点
//
//  Created by SeacenLiu on 2018/9/18.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 
 示例：
 
 给定一个链表: 1->2->3->4->5, 和 n = 2.
 
 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 说明：
 
 给定的 n 保证是有效的。
 
 进阶：
 
 你能尝试使用一趟扫描实现吗？
 */

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
};

ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == nullptr || n == 0)
        return nullptr;
    
    ListNode *
    ListNode *p = head;
    
    for(int i = 0; i < n - 1; ++i)
        if (fp->next != nullptr)
           fp=fp->next;
    else
        return nullptr;

    while (fp->next != nullptr) {
        fp=fp->next;
        p=p->next;
    }
    
    if (p->next != nullptr) {
        ListNode* pNext = p->next;
        p->val = pNext->val;
        p->next = pNext->next;
        delete pNext;
        pNext = nullptr;
    } else if (head == p){
        delete p;
        p = nullptr;
        return nullptr;
    } else {
        ListNode* pNode = head;
        while (pNode -> next != p) {
            pNode = pNode -> next;
        }
        
        pNode->next = nullptr;
        delete p;
        p = nullptr;
    }
    return head;
}

void PrintList(ListNode *h) {
    while (h != nullptr) {
        std::cout << h->val << " ";
        h = h -> next;
    }
    std::cout << std::endl;
}

ListNode* CreateNode(int a[],int length) {
    ListNode* n = new ListNode();
    ListNode* h = n;
    for (int i = 0; i < length; i++) {
        ListNode *node = new ListNode();
        node->val = a[i];
        n->next = node;
        n = node;
    }
    return h->next;
}

int main(int argc, const char * argv[]) {
    
    int a[5] = {1, 2, 3, 4, 5};
    ListNode* p1 = CreateNode(a, 5);
    PrintList(p1);
    removeNthFromEnd(p1, 2);
    PrintList(p1);
    
    int b[2] = {1, 2};
    ListNode* p2 = CreateNode(b, 2);
    PrintList(p2);
    PrintList(removeNthFromEnd(p2, 2));
    
    int c[2] = {1, 2};
    ListNode* p3 = CreateNode(c, 2);
    PrintList(p3);
    PrintList(removeNthFromEnd(p3, 1));
    
    std::cout << "Hello, World!\n";
    return 0;
}
