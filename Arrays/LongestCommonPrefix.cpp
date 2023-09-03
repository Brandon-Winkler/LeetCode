#include<vector>
#include<iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = strs[0]; // initialize prefix to empty string

        for(int i=0;i<strs.size();++i){ // loop through first string in strings array starting at index 1
            while(strs[i].find(prefix) != 0){ // continue looping while the prefix is not found at the beginning of the current string.
                prefix = prefix.substr(0, prefix.length()-1); // remove the last character from prefix to make it shorter.
                if (prefix.empty()) {
                    return ""; // If prefix becomes empty, there's no common prefix.
                }
            }
        }
        return prefix;
    }
};

int main(){
    // initialize array of strings
    std::vector<std::string> strs1 = {"trivial","trininty","triple","triathlon","trigonometry","trigger","triumpth","trifecta"};
    std::vector<std::string> strs2 = {"easy","peezy","lemon","squeezy"};

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"Prefix for string one is: "<<Solution.longestCommonPrefix(strs1)<<'\n';
    std::cout<<"Prefix for string two is: "<<Solution.longestCommonPrefix(strs2)<<'\n';
    
    return 0;
}