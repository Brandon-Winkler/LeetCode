#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        for (const auto& c : s) {
            if (map.find(c) != map.end()) {
                // if input starts with a closing bracket.
                if (stack.empty() || stack.top() != map[c]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

int main() {
    //initialize strings
    std::string parens1 = "(({[]}))", parens2 = "({]})", parens3 = "[](){}";
    //initialize solutions class
    Solution solution;

    //print results
    std::cout << solution.isValid(parens1) << '\n';
    std::cout << solution.isValid(parens2) << '\n';
    std::cout << solution.isValid(parens3) << '\n';
    
    return 0;
}

