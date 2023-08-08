#include <unordered_set>
#include <string>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> set; // create a set to keep track of characters we have seen
        int l=0, res=0; // initialize variables: one left pointer to keep track of left side of window, and one for our result

        for(int r=0;r<s.size();++r){ // for loop that iterates through string and keeps track of right side of window
            while(set.find(s[r]) != set.end()){ // if we find a repeated element in our set then erase that repeated element and increment left side of window
                set.erase(s[l]);
                ++l;
            }
            // otherwise insert element at right side of window and get the max between the current result and right minus left plus 1
            set.insert(s[r]);
            res = std::max(res, r-l+1);
        }
        return res;
    }
};

int main(){
    // initialize strings
    std::string str1="abcabcbb";
    std::string str2="bbbbbb";
    std::string str3="";

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The longest substring in str1 is: "<<Solution.lengthOfLongestSubstring(str1)<<'\n';
    std::cout<<"The longest substring in str2 is: "<<Solution.lengthOfLongestSubstring(str2)<<'\n';
    std::cout<<"The longest substring in str3 is: "<<Solution.lengthOfLongestSubstring(str3)<<'\n';
    
    return 0;
}
