//
//  main.cpp
//  合并K个排序链表
//
//  Created by SeacenLiu on 2018/9/20.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 
 示例:
 
 输入:
 [
 1->4->5,
 1->3->4,
 2->6
 ]
 输出: 1->1->2->3->4->4->5->6
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// LeetCode上的解答 16ms
struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }
};

/// LeetCode上的解答 20ms
/**
class Solution {
public:
    ListNode *merge2Lists(ListNode *list1_head, ListNode *list2_head,
                          ListNode *merged_head, ListNode *merged_tail)
    {
        // 两种结束递归的情况
        if (list1_head == NULL)
        {
            merged_tail->next = list2_head;
            return merged_head;
        }
        else if (list2_head == NULL)
        {
            merged_tail->next = list1_head;
            return merged_head;
        }

        // 需要继续递归的情况
        else if (list1_head->val <= list2_head->val)
        {
            merged_tail->next = list1_head;
            // 尾递归
            return merge2Lists(list1_head->next, list2_head, merged_head, merged_tail->next);
        }
        else
        {
            merged_tail->next = list2_head;
            // 尾递归
            return merge2Lists(list1_head, list2_head->next, merged_head, merged_tail->next);
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int lists_num = lists.size();
        if (lists_num == 0)
            return NULL;

        ListNode *dummyHead = new ListNode(-1);
        while (lists_num > 1)
        {
            for (int i = 0; i < lists_num / 2; i++)
            {
                // 通过 dummyHead ，避免对 “merged_head == NULL && merged_tail == NULL”情况进行额外判断处理
                dummyHead->next = NULL;
                lists[i] = merge2Lists(lists[i], lists[lists_num - 1 - i], dummyHead, dummyHead)->next;
            }
            // “简化问题”的过程，就是不断减半lists_num的过程
            lists_num = (lists_num + 1) / 2;
        }
        delete dummyHead;
        // 经过log_2(k)次减半，lists 中只剩下一个sortedList
        return lists[0];
    }
};
*/

/** 148 ms
class Solution {
 public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        ListNode *tail = nullptr;
        ListNode *ret = nullptr;
        
        ListNode *pMin = nullptr;
        int index = 0, min = 0;
        while (!lists.empty()) {
            // find min
            index = -1;
            pMin = nullptr;
            for (auto list: lists) {
                index++;
                if (list != nullptr) {
                    if (pMin == nullptr) {
                        pMin = list;
                        min = index;
                    } else if (list->val < pMin->val) {
                        pMin = list;
                        min = index;
                    }
                }
            }
            // remove min
            if (pMin == nullptr)
                return ret;
            lists.erase(lists.begin()+min);
            // add min
            if (tail == nullptr) {
                tail = pMin;
                ret = tail;
            } else {
                tail->next = pMin;
                tail = tail->next;
            }
            // insert
            pMin = pMin->next;
            if (pMin != nullptr)
                lists.push_back(pMin);
        }
        return ret;
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
    
    ListNode *l1 = CreateNode({1, 4, 5});
    PrintList(l1);
    ListNode *l2 = CreateNode({1, 3, 4});
    PrintList(l2);
    ListNode *l3 = CreateNode({2, 6});
    PrintList(l3);
    
    ListNode *l4 = nullptr;//CreateNode({1});
    PrintList(l4);
    
    vector<ListNode*> lists = {l4};//{l1, l2, l3};
    Solution sol = Solution();
    PrintList(sol.mergeKLists(lists));
    
    std::cout << "Hello, World!\n";
    return 0;
}
