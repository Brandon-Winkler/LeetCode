#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26); // initialize vector with a capacity of 26 to keep track of letter counts
        // initialize variables:
        int maxCount=0, // maxCount for keeping track of max that we have seen so far  
            maxLength=0, // maxLength for our result
            l=0; // left side of window

        for (int r=0;r<s.size();++r){ // loop through string s with r representing right side of window
            ++count[s[r] - 'A']; // increment the count of the current letter
            maxCount = std::max(maxCount, count[s[r] - 'A']); // assign maxCount to max between the current max and the count of the current letter
            
            // If the number of characters to be replaced exceeds k,
            // move the start of the window to the right.
            while (r - l + 1 - maxCount > k){
                --count[s[l] - 'A'];
                ++l;
            }
            // Update the maxLength with the length of the current valid substring.
            maxLength = std::max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};

int main(){
    // initialize test strings
    std::string str1="AABABBA";
    std::string str2="HCBAECTCT";
    std::string str3="EEEEEE";

    // class instance
    Solution Solution;

    // output
    std::cout<<"Solution for string 1: "<<Solution.characterReplacement(str1, 1)<<'\n';
    std::cout<<"Solution for string 2: "<<Solution.characterReplacement(str2, 2)<<'\n';
    std::cout<<"Solution for string 3: "<<Solution.characterReplacement(str3, 4)<<'\n';

    return 0;
}

