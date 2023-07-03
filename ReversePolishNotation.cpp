#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {

        // initialize map of operators and their functions:
        std::unordered_map<std::string, std::function<int(int, int)>> operators;
        operators["+"] = [](int a, int b) { return a + b; };
        operators["-"] = [](int a, int b) { return a - b; };
        operators["*"] = [](int a, int b) { return a * b; };
        operators["/"] = [](int a, int b) { return a / b; };

        // initialize stack and operand variables
        std::stack<int> nums;
        int operand1, operand2;

        // loop through tokens
        for(int i = 0; i < tokens.size(); ++i) {
           std::string token = tokens[i];

            // if the token isn't an operator convert it to an int and push onto stack
           if(operators.find(token) == operators.end()) {
               int num = stoi(token);
               nums.push(num);
           }

           // otherwise take the two top numbers and get their result of operator at i
           else {
               operand1 = nums.top();
               nums.pop();
               operand2 = nums.top();
               nums.pop();
               int res = operators[token](operand2, operand1);
               nums.push(res);
           }
        }
        return nums.top();
    }
};

int main() {

    // initialize vector of tokens
    std::vector<std::string> equation = {"2","5","*","4","+","3","2","*","1","+","/"};

    // create class instance
    Solution Solution;

    // print result
    std::cout << Solution.evalRPN(equation) << '\n';
    return 0;
}