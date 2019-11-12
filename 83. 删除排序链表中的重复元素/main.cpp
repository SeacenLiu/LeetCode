//
//  main.cpp
//  83. 删除排序链表中的重复元素
//
//  Created by SeacenLiu on 2019/11/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 
 示例 1:
 
 输入: 1->1->2
 输出: 1->2
 示例 2:
 
 输入: 1->1->2->3->3
 输出: 1->2->3
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* deleteNode(ListNode *head, ListNode *preNode) {
        if (nullptr == preNode) {
            return head->next;
        }
        ListNode *needDelete = preNode->next;
        if (needDelete == nullptr) {
            return head;
        }
        preNode->next = needDelete->next;
        delete needDelete;
        return head;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        if (cur == nullptr) {
            return head;
        }
        while (cur) {
            if (pre && cur && pre->val == cur->val) {
                head = deleteNode(head, pre);
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

void test(vector<int> arr) {
    cout << "===============================" << endl;
    for (int val: arr) {
        cout << val << "->";
    }
    cout << endl;
    ListNode *head = new ListNode(0);
    ListNode *dom = head;
    for (int val: arr) {
        ListNode *tmp = new ListNode(val);
        head->next = tmp;
        head = head->next;
    }
    head = dom->next;
    ListNode *res = Solution().deleteDuplicates(head);
    while (res) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;
    cout << "===============================" << endl;
}

int main(int argc, const char * argv[]) {
    test({1,1,2});
    test({1,1,2,3,3});
    std::cout << "Hello, World!\n";
    return 0;
}
