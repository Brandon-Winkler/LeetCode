#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {

        // initialize stack and running total
        std::stack<int> stack;
        int total = 0;
        
        // loop through string list
        for(int i = 0; i < operations.size(); ++i) {
            std::string token = operations[i];

            if(token == "+") {

                // take the top two numbers on the stack, save and pop them
                int top1 = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.pop();

                // push them back onto the stack
                stack.push(top2);
                stack.push(top1);

                // sum the two tops and push the sum onto the stack 
                // add the sum to the running total
                int sum = top1 + top2;
                stack.push(sum);
                total += sum;
            }
            else if(token == "C") {

                // substract top of the stack from the total and pop the stack
                total -= stack.top();
                stack.pop();
            }
            else if(token == "D") {

                // double the top of the stack, add the product to the total
                // push the product onto the stack
                int prod = 2 * stack.top();
                total += prod;
                stack.push(prod);
            }
            else {

                // convert the string to an int, add it to the total and push onto the stack
                total += std::stoi(token);
                stack.push(std::stoi(token));
            }
        }
        return total;
    }
};

int main() {

    // vector of strings:
    std::vector<std::string> list = {"5","2","4","C","D","9","+","+"};

    // class instance
    Solution Solution;

    // print output
    std::cout<< Solution.calPoints(list) << '\n';

    return 0;
}