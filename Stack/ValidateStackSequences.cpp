#include <stack>
#include <iostream>
#include <vector>

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        // initialize stack and interator
        std::stack<int> stk;
        int n = 0;

        // loop through pushed vector and push element at i onto stack
        for(int i = 0; i < pushed.size(); ++i) {
            stk.push(pushed[i]);

            // loop through popped vector
            while( n < popped.size() ) {
                // if the stack is empty and top is equal to element at popped[n]
                // then pop from stack and increment forword in popped, otherwise break out of popped loop
                if(!stk.empty() && stk.top() == popped[n]) {
                    stk.pop();
                    ++n;
                } 
                else {
                    break;
                }
            }
        } 
        return stk.empty();
    }
};

int main() {

    // initialize pushed and popped vectors
    std::vector <int> push1 = {1,2,3,4,5};
    std::vector <int> pop1 = {4,5,3,2,1};
    std::vector <int> push2 = {0,2,1};
    std::vector <int> pop2 = {0,1,2};
    std::vector <int> pop3 = {4,3,5,1,2};

    // create class instance
    Solution Solution;

    // print output
    std::cout << Solution.validateStackSequences(push1,pop1) << '\n';
    std::cout << Solution.validateStackSequences(push2, pop2) << '\n';
    std::cout << Solution.validateStackSequences(push1, pop3) << '\n';


    return 0;
}