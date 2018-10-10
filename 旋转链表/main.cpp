//
//  main.cpp
//  旋转链表
//
//  Created by SeacenLiu on 2018/9/28.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 
 示例 1:
 
 输入: 1->2->3->4->5->NULL, k = 2
 输出: 4->5->1->2->3->NULL
 解释:
 向右旋转 1 步: 5->1->2->3->4->NULL
 向右旋转 2 步: 4->5->1->2->3->NULL
 示例 2:
 
 输入: 0->1->2->NULL, k = 4
 输出: 2->0->1->NULL
 解释:
 向右旋转 1 步: 2->0->1->NULL
 向右旋转 2 步: 1->2->0->NULL
 向右旋转 3 步: 0->1->2->NULL
 向右旋转 4 步: 2->0->1->NULL
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 非负数 0
 
 保存头
 数 k
 将后面的逐个丢去前面
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode* cur = head;
        int len = 1;
        for(;cur->next!=nullptr;cur = cur->next)
        {
            len ++;
        }
        k = len - k % len;
        cur->next = head;
        for(int i = 0;i< k;i++)
        {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
        
    }
};

/** 超烂
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k < 0 || head == nullptr) return nullptr;
        if (k == 0 || head->next == nullptr) return head;
        ListNode *p = head;
        int count = 1;
        for (int i = 1; i < k; i ++) {
            if (p->next != nullptr) {
                p = p->next;
                count++;
            } else {
                break;
            }
        }
        
        if (p->next == nullptr && k%count == 0)
            return head;
        
        if (count < k) {
            while (k > count) {
                k -= count;
            }
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        
        return head;
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

ListNode* CreateNode(vector<int> arr) {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    for (auto i: arr) {
        ListNode *node = new ListNode(i);
        tail->next = node;
        tail = node;
    }
    return head->next;
}

int main(int argc, const char * argv[]) {
    ListNode *t1 = CreateNode({1, 2, 3, 4, 5});
    Solution sol = Solution();
    PrintList(t1);
    PrintList(sol.rotateRight(t1, 2));
    
    ListNode *t2 = CreateNode({0, 1, 2});
    PrintList(t2);
    PrintList(sol.rotateRight(t2, 4));
    
    ListNode *t3 = CreateNode({0});
    PrintList(t3);
    PrintList(sol.rotateRight(t3, 4));
    
    ListNode *t4 = CreateNode({1, 2});
    PrintList(t4);
    PrintList(sol.rotateRight(t4, 0));
    
    ListNode *t5 = CreateNode({1, 2});
    PrintList(t5);
    PrintList(sol.rotateRight(t5, 1));
    
    ListNode *t6 = CreateNode({4, 5});
    PrintList(t6);
    PrintList(sol.rotateRight(t6, 2));
    
    ListNode *t7 = CreateNode({4, 5});
    PrintList(t7);
    PrintList(sol.rotateRight(t7, 4));
    
    std::cout << "Hello, World!\n";
    return 0;
}
