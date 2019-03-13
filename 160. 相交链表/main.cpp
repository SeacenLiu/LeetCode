//
//  main.cpp
//  160. 相交链表
//
//  Created by SeacenLiu on 2019/3/11.
//  Copyright © 2019 成. All rights reserved.
//

/**
 编写一个程序，找到两个单链表相交的起始节点。
 
 如下面的两个链表：
 [](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)
 在节点 c1 开始相交。
 
 示例 1：
 [](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)
 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 输出：Reference of the node with value = 8
 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 
 
 示例 2：
 [](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)
 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 输出：Reference of the node with value = 2
 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 
 
 示例 3：
 [](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)
 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 输出：null
 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 解释：这两个链表不相交，因此返回 null。
 
 注意：
 如果两个链表没有交点，返回 null.
 在返回结果后，两个链表仍须保持原有的结构。
 可假定整个链表结构中没有循环。
 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        /**
         定义两个指针, 第一轮让两个到达末尾的节点指向另一个链表的头部, 最后如果相遇则为交点(在第一轮移动中恰好抹除了长度差)
         两个指针等于移动了相同的距离, 有交点就返回, 无交点就是各走了两条指针的长度
         **/
        if(!headA || !headB) return nullptr;
        ListNode* pA = headA, *pB = headB;
        // 在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头, 而第二轮体现在如果pA或pB相交就返回交点, 不相交最后就是nullptr==nullptr
        while (pA!=pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;
        int diff = 0;
        while (a->next) {
            ++diff;
            a = a->next;
        }
        while (b->next) {
            --diff;
            b = b->next;
        }
        ListNode *front = headA, *last = headB;
        if (diff < 0) {
            front = headB;
            last = headA;
            diff = -diff;
        }
        while (diff--) {
            front = front->next;
        }
        while (front != last) {
            front = front->next;
            last = last->next;
            if (!front || !last)
                return nullptr;
        }
        return front;
    }
};

// 链表创建
ListNode* creat(vector<int> a) {
    ListNode *dmp = new ListNode(-1);
    ListNode *h = dmp;
    for (auto v: a) {
        ListNode *tmp = new ListNode(v);
        dmp->next = tmp;
        dmp = dmp->next;
    }
    return h->next;
}

void test(vector<int> a, int la, vector<int> b, int lb, int ans) {
    cout << "------------------" << endl;
    for (auto v: a) cout << v << " ";
    cout << endl;
    cout << la << endl;
    for (auto v: b) cout << v << " ";
    cout << endl;
    cout << la << endl;
    cout << "aim: " << ans << endl;
    vector<int> a1(a.begin(), a.begin()+la);
    ListNode* ha = creat(a1);
    vector<int> b1(b.begin(), b.begin()+lb);
    ListNode* hb = creat(b1);
    
    vector<int> c(a.begin()+la,a.end());
    ListNode* common = creat(c);
    
    ListNode *p1 = ha;
    while (p1->next) {
        p1 = p1->next;
    }
    p1->next = common;
    p1 = hb;
    while (p1->next) {
        p1 = p1->next;
    }
    p1->next = common;
    
    Solution sol = Solution();
    ListNode *res = sol.getIntersectionNode(ha, hb);
    if (res) {
        cout << res->val << endl;
    }
    
    delete p1;
    delete ha;
    delete hb;
    delete res;
    cout << "------------------" << endl;
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    test({4,1,8,4,5}, 2, {5,0,1,8,4,5}, 3, 8);
    return 0;
}
