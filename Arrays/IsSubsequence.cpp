#include <iostream>
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int j=0; // initialize variable to beginning of first string
        for(int i=0;i<t.length()&&j<s.size();++i){ // loop through first and second string
            if(s[j]==t[i]) ++j; // if character at first is equal to second iterate through first
        }
        return (j==s.size()); // if first iterator gets all the way to end return true otherwise return false
    }
};

int main() {
    // initialize strings
    std::string abc = "abc";
    std::string azc = "azc";
    std::string ahbgdc = "ahbgdc";

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The truthiness of whether abc is a subsequece of ahbgdc is: "<<Solution.isSubsequence(abc, ahbgdc)<<'\n';
    std::cout<<"The truthiness of whether azc is a subsequece of ahbgdc is: "<<Solution.isSubsequence(azc, ahbgdc)<<'\n';
    
    return 0;
}

