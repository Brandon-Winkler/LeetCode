#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
    }
};

// Utility fuction to print vector of vectors
void printVectorOfVectors(const vector<vector<int>>& vec) {
    for(const vector<int>& innerVec : vec){
        for(int num : innerVec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main(){
    return 0;
}