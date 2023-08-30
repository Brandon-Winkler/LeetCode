#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s){
        int count = 0; // variable to return size of last word

        for(int i=s.size()-1;i>=0;--i){ // loop through given string
            if(s[i] != ' ') ++count; // count up if value at index i is not a space
            if(s[i] == ' ' && count >= 1) break; // if value at i is a space and count is greater than 1 we have found size of last word
        }
        return count;
    }
};

int main() {
    // initialize strings
    std::string s1 = "Hello World";
    std::string s2 = "  fly me    to  the moon   ";
    std::string s3 = "a";

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The length of the last word in string 1 is: "<<Solution.lengthOfLastWord(s1)<<'\n';
    std::cout<<"The length of the last word in string 2 is: "<<Solution.lengthOfLastWord(s2)<<'\n';
    std::cout<<"The length of the last word in string 3 is: "<<Solution.lengthOfLastWord(s3)<<'\n';

    return 0;
}