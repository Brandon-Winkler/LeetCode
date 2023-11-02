#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void removeDuplicates(vector<int>& nums) {
        int k = 1;                          // set variable to track index of duplicates
        int prev = nums[0];                 // set previous variable to first element in vector
        for(int i=1;i<nums.size();++i){     // loop through vector
            if(nums[i] != prev){            // if value at ith index is not equal to the previous value
                nums[k] = nums[i];          // set value at kth index to value at ith index
                ++k;                        // increment kth index
            }
            prev = nums[i];                 // set previous variable to value at ith index
        }
        return;
    }
};

// Utility fuction to print vector
void printVector(std::vector<int> v) {
    std::cout<<"[";
    for(int i=0;i<v.size();++i){
        std::cout<<" "<<v[i]<<" ";
    }
    std::cout<<"]"<<'\n';
}

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {1,2,2,3,4,4,4,5};
    vector<int> v2 = {0,0,3,4,5,5};
    vector<int> v3 = {1,2,2,3,4,5,6,6};

    cout<<"Vectors before removal:"<<'\n';
    printVector(v1);
    printVector(v2);
    printVector(v3);
    cout<<'\n';

    // solution class instance
    Solution Solution;

    // remove duplicates
    Solution.removeDuplicates(v1);
    Solution.removeDuplicates(v2);
    Solution.removeDuplicates(v3);

    // output
    cout<<"Vectors after the removal: "<<'\n';
    printVector(v1);
    printVector(v2);
    printVector(v3);
    cout<<'\n';

    return 0;
}