#include "SpecialStack.h"

void SpecialStack::push(int value) {
    stack.push(value);
}

void SpecialStack::pop() {
    if (stack.empty()) {
        throw std::underflow_error("Stack is empty!");
    }
    stack.pop();
}

void SpecialStack::popEven() {
    if (stack.empty()) {
        throw std::underflow_error("Stack is empty!");
    }

    std::stack<int> tempStack;
    bool removed = false;

    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();

        if (!removed && top % 2 == 0) {
            removed = true;
        } else {
            tempStack.push(top);
        }
    }

    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }

    if (!removed) {
        throw std::logic_error("No even numbers in the stack!");
    }
}

void SpecialStack::popOdd() {
    if (stack.empty()) {
        throw std::underflow_error("Stack is empty!");
    }

    std::stack<int> tempStack;
    bool removed = false;

    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();

        if (!removed && top % 2 != 0) {
            removed = true;
        } else {
            tempStack.push(top);
        }
    }

    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }

    if (!removed) {
        throw std::logic_error("No odd numbers in the stack!");
    }
}

int SpecialStack::peek() {
    if (stack.empty()) {
        throw std::underflow_error("Stack is empty!");
    }
    return stack.top();
}

bool SpecialStack::empty() const {
    return stack.empty();
}

void SpecialStack::printStack() {
    if (stack.empty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    std::stack<int> tempStack = stack;
    std::cout << "Stack contents (top to bottom): ";
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std:: endl;
}
return 0
