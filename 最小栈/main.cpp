//
//  main.cpp
//  最小栈
//
//  Created by SeacenLiu on 2018/9/20.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 示例:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m_main = stack<int>();
        m_min = stack<int>();
    }
    
    void push(int x) {
        m_main.push(x);
        if (m_min.size() == 0 || x < m_min.top()) {
            m_min.push(x);
        } else {
            m_min.push(m_min.top());
        }
    }
    
    void pop() {
        m_main.pop();
        m_min.pop();
    }
    
    int top() {
        return m_main.top();
    }
    
    int getMin() {
        return m_min.top();
    }
private:
    stack<int> m_main, m_min;
};

int main(int argc, const char * argv[]) {
    MinStack stack = MinStack();
    stack.push(1);
    stack.push(2);
    cout << stack.getMin() << endl;
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    cout << stack.getMin() << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
