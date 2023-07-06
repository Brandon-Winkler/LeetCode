#include <string>
#include <iostream>

class Solution {
public:
    std::string removeStars(std::string s) {

        // create empty string
        std::string str = "";

        // loop through given string
        for(int it = 0; it < s.size(); ++it) {
            char c = s[it];

            // pop if we see a star
            if(c == '*') {
                str.pop_back();
            }
            // push if we don't see a star
            else {
                str.push_back(c);
            }
        }
        return str;
    }
};

int main() {

    // make string with stars
    std::string leetcode = "leet**cod*e";
    // create class instance
    Solution Solution;
    // print output
    std::cout << Solution.removeStars(leetcode) << '\n';

    return 0;
}