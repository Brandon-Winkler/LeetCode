#include <iostream>
#include <stack>

class MinStack {
private:

    // create two stacks, one for our initial stack and one for the minimum
    std::stack<int> stack;
    std::stack<int> minStack;

public:

    void push(int val) {
        
        // push the value into our initial stack
        stack.push(val);

        /*
        -compare the value to the minStack top to find the minimum otherwise compare it to itself
        -push minimum between the two onto minStack
        */ 
        val = std::min(val, (minStack.empty() ? val : minStack.top()));
        minStack.push(val);
    }

    void pop() {

        // pop from both stacks
        stack.pop();
        minStack.pop();
    }

    int top() {

        // return the initial stacks top
        return stack.top();
    }

    int getMin() {

        // get the minStack top
        return minStack.top();
    }
};

int main() {
    
    // create minStack instance
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    // print the output
    std::cout << "Minimum: " << minStack.getMin() << std::endl;  // Output: Minimum: 1
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl;  // Output: Top: 2
    std::cout << "Minimum: " << minStack.getMin() << std::endl;  // Output: Minimum: 2

    return 0;
}