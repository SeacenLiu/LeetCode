//
//  main.cpp
//  排序链表
//
//  Created by SeacenLiu on 2018/11/26.
//  Copyright © 2018 成. All rights reserved.
//

/*
 在 O(nlogn) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 
 示例 1:
 
 输入: 4->2->1->3
 输出: 1->2->3->4
 示例 2:
 
 输入: -1->5->3->4->0
 输出: -1->0->3->4->5
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 快速排序:
 * 将结点看成数 head mid tail
 * 交换的时候是交换 node->val
 * 分区点直接拿第一个做，从前往后遍历
 归并排序:
 * 快慢指针获取中间的结点
 * pre->next = NULL 分割链表
 * 对比合并
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre, *slow, *fast;
        pre = slow = fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; // 将链表一分为二，分割点为 pre
        return merge(sortList(head), sortList(slow));
    }
private:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = (l1 == NULL) ? l2 : l1;
        return head->next;
    }
};

// 快速排序
/**
class Solution {
private:
    ListNode* partition(ListNode *low, ListNode *high) {
        int pivot = low->val;
        ListNode *loc = low;
        for (ListNode *i = low->next; i != high; i = i->next) {
            if (i ->val < pivot) {
                loc = loc ->next;
                swap(i->val, loc->val);
            }
        }
        swap(loc->val, low->val);
        return loc;
    }
    
    void quick_sort(ListNode *head, ListNode *tail) {
        if (head == tail || head->next == tail) return;
        ListNode *mid = partition(head, tail);
        quick_sort(head, mid);
        quick_sort(mid->next, tail);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        quick_sort(head, nullptr);
        return head;
    }
};
 */

ListNode *CreateList(vector<int> a) {
    ListNode *head = new ListNode(0), *p = head;
    for (auto v: a) {
        ListNode *node = new ListNode(v);
        p->next = node;
        p = p->next;
    }
    return head->next;
}

void ShowList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

void Test(ListNode* head) {
    cout << "---------------" << endl;
    ShowList(head);
    Solution *sol = new Solution();
    ShowList(sol->sortList(head));
    cout << "---------------" << endl;
}

int main(int argc, const char * argv[]) {
    ListNode *h1 = CreateList({4, 2, 1, 3});
    Test(h1);
    return 0;
}
