#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <iostream>
#include <stack>
#include <stdexcept>

class SpecialStack {
private:
    std::stack<int> stack;

public:
    void push(int value);
    void pop();
    void popEven();
    void popOdd();
    int peek();
    bool empty() const;
    void printStack();
};

#endif
