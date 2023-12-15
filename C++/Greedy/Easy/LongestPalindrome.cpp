#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> table;                      // table to get freqencey of each letter
        int ans = 0;                                        // answer for output

        for(int i=0;i<s.size();++i) ++table[s[i]];          // create frequency table

        bool oddFreq = false;                               // variable to see if there is an odd frequency in table

        for(auto it=table.begin();it!=table.end();++it){
            if(it->second%2 == 0){                          // if frequency of character is even add it to the answer
                ans += it->second;
            }
            else{                                           // otherwise add the frequency minus 1 to the answer and set the odd frequency to true
                ans += it->second-1;
                oddFreq = true;
            }
        }
        if(oddFreq) ++ans;                                  // if odd frequency is true the add 1 to the answer
        
        return ans;
    }
};

// driver program
int main(){
    // solution class instance
    Solution Solution;

    // output
    cout<<"The length of the longest palindrome for abccccdd is "<<Solution.longestPalindrome("abccccdd")<<'\n';
    cout<<"The length of the longest palindrome for a is "<<Solution.longestPalindrome("a")<<'\n';
    cout<<"The length of the longest palindrome for llxcyllzzz is "<<Solution.longestPalindrome("llxcyllzzz")<<'\n';
    return 0;
}