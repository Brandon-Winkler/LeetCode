#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0;
        int hi = s.size()-1;

        while(lo < hi){
            int temp = s[lo];
            s[lo] = s[hi];
            s[hi] = temp;
            ++lo;
            --hi;
        }
        return;
    }
};

// function for printing strings
void printString(vector<char>& s){
    for(int i=0;i<s.size();++i){
        cout<<s[i];
    }
    cout<<'\n';
}

// driver program
int main(){
    // initialize strings
    vector<char> s1 = {'h','e','l','l','o'};
    vector<char> s2 = {'r','a','c','e','c','a','r'};

    cout<<"Strings before reversal: "<<'\n';
    printString(s1);
    printString(s2);

    // solution class instance
    Solution Solution;

    Solution.reverseString(s1);
    Solution.reverseString(s2);

    cout<<"Strings after reversal: "<<'\n';
    printString(s1);
    printString(s2);

    return 0;
}