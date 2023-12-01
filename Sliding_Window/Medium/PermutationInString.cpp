#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    }
};

// driver program
int main(){
    // initialize strings
    string str1 = "eidbaooo";
    string str2 = "xlinehgioac";

    // solution class instance
    Solution Solution;

    bool s1 = Solution.checkInclusion("ab",str1);
    bool s2 = Solution.checkInclusion("lein",str2);

    if(s1) cout<<"The permutation exists in string 1"<<'\n';
    else cout<<"The permutation does not exist in string 1"<<'\n';

    if(s2) cout<<"The permutation exists in string 2"<<'\n';
    else cout<<"The permutation does not exist in string 2"<<'\n';
    
    return 0;
}