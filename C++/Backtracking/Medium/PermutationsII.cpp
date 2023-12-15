#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
    }
};

// Utility fuction to print vector of vectors
void printVectorOfVectors(const vector<vector<int>>& vec){
    for(const vector<int>& innerVec : vec){
        cout<<"[";
        for(int num : innerVec){
            cout<<" "<<num<<" ";
        }
        cout<<"]"<<endl;
    }
}

// driver program
int main(){
    // initialize number array
    vector<int> n1 = {1,1,2};
    vector<int> n2 = {1,2,3};

    // solution class instance
    Solution Solution;

    vector<vector<int>> p1 = Solution.permuteUnique(n1);
    vector<vector<int>> p2 = Solution.permuteUnique(n2);

     // outputs
    cout<<"All unique permutations of vector one: "<<'\n';
    printVectorOfVectors(p1);
    cout<<'\n';

    cout<<"All unique permutations of vector two: "<<'\n';
    printVectorOfVectors(p2);
    cout<<'\n';
    return 0;
}