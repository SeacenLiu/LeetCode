//
//  main.cpp
//  用队列实现栈
//
//  Created by SeacenLiu on 2018/5/7.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 使用队列实现栈的下列操作：
 push(x) --元素 x 入栈
 pop() -- 移除栈顶元素
 top() -- 获取栈顶元素
 empty() --返回栈是否为空
 注意:
 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque (双端队列) 来模拟一个队列 , 只要是标准的队列操作即可。
 假设所有操作都是有效的 (例如, 对一个空的栈不会调用 pop 或者 top 操作)。
 */

#include <iostream>
#include <vector>
using namespace std;

class MyStack {
    private:
    vector<int> a;
    public:
    /** Initialize your data structure here. */
    MyStack() {
        a = vector<int>();
    }
    
    ~MyStack() {
        a.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (empty()) {
            return -1;
        }
        int value = top();
        a.pop_back();
        return value;
    }
    
    /** Get the top element. */
    int top() {
        return a[a.end()-a.begin()-1];
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

int main(int argc, const char * argv[]) {
    MyStack obj = MyStack();
    obj.push(1);
    cout << obj.pop() << endl;
//    int param_2 = obj.pop();
//    int param_3 = obj.top();
//    bool param_4 = obj.empty();
    return 0;
}
