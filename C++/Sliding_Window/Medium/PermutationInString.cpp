#include<string>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPermutation(vector<int>& count){
        for(int i=0;i<26;i++){
            if(count[i] != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size()) return false;

        vector<int> count(26);
        for(int i=0;i<s1.size();i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        if(isPermutation(count)) return true;

        for(int i=s1.size();i<s2.size();i++){
            count[s2[i]-'a']--;
            count[s2[i-s1.size()]-'a']++;
            if(isPermutation(count)) return true;
        }
        return false;
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