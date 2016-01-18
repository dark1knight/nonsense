#include <mystack.h>

// standard headers
#include <iostream>

int main() {
    nonsense::MyStack<int> int_stack;

    int_stack.push(3);
    int_stack.push(10);

    std::cout << int_stack.top() << "\n";
    int_stack.pop();
    std::cout << int_stack.top() << "\n";
    int_stack.pop();

    nonsense::MyStack<int> stack_2;
    stack_2.push(10);
    stack_2.push(1);
    int_stack = stack_2;
    std::cout << int_stack.top() << "\n";
    int_stack.pop();
    std::cout << int_stack.top() << "\n";
    int_stack.pop();


}
