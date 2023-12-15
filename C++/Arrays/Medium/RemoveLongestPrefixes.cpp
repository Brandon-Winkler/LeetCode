#include<string>
#include<iostream>
using namespace std;

class Solution{
public:
    string removeLongestPalindromes(string s){
        while(!s.empty()){                                     // loop through given string
            string pal = "";                                   // initialize palindtrome to empty string
            for(int i=s.size();i>=0;--i){                      // start from end of string and go down to find prefixes
                string pre = s.substr(0, i);                   // intialize prefix from beginning of the string down to the ith index
                string rev = pre;                              // set current string to current prefix and reverse it 
                reverse(rev.begin(), rev.end());
                if(rev == pre && pre.size() > pal.size()){     // set palindrome to prefix if reversed prefix is equal to prefix and current prefix is longer than the current palindrome
                    pal = pre;
                }
            }
            if(pal.size() >= 2){                                // if palindrome size is greater than 2 remove it from the string
                auto found = s.find(pal);
                s.erase(found, pal.size());
            }
            else{                                               // otherwise break from the loop so that we don't remove any palindromes whose size is 1
                break;
            }
        }
        return s;
    }
};

// driver program
int main(){
    // initialize strings
    string s1 = "aaacodedoc";
    string s2 = "";
    string s3 = "a";
    string s4 = "bbbbabacaabbaa";

    // solution class instance
    Solution Solution;

    // output
    cout<<"After the removal of all the longest palindromes string 1 is "<<Solution.removeLongestPalindromes(s1)<<'\n';
    cout<<"After the removal of all the longest palindromes string 2 is "<<Solution.removeLongestPalindromes(s2)<<'\n';
    cout<<"After the removal of all the longest palindromes string 3 is "<<Solution.removeLongestPalindromes(s3)<<'\n';
    cout<<"After the removal of all the longest palindromes string 4 is "<<Solution.removeLongestPalindromes(s4)<<'\n';
    return 0;
}