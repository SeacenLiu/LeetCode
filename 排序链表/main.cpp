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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
