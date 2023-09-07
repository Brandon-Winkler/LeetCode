#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1); // initialize result vector to nums size capacity and one in first element
        
        int prefix = 1; // set prefix to one to calculate the products to the left of ith index 
        for(int i=0;i<nums.size();++i){ // loop through nums
            result[i] = prefix;         // set value at i index in result to prefix so that we have all prefix values in result 
            prefix = prefix*nums[i];    // set prefix to product of ith value and the prefix to update the prefix
        }
        int postfix = 1; // set postfix to one to calculate the products to the right of the ith index
        for (int i=nums.size()-1;i>=0;--i){ // loop through nums
            result[i] = result[i]*postfix;  // set value at i index in result to postfix multiplied by value at i index to get products
            postfix = postfix*nums[i];      // set postfix to product of ith value and the postfix to update the postfix
        }
        return result;
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

// Driver program
int main() {
    // intialize vectors
    std::vector<int> v1 = {3,2,4,5,5,6};
    std::vector<int> v2 = {5,8,1,7,0,4};
    
    // create class instance
    Solution Solution;

    // solution vectors
    std::vector<int> s1 = Solution.productExceptSelf(v1);
    std::vector<int> s2 = Solution.productExceptSelf(v2);

    // output
    std::cout<<"Products of first array: "<<'\n';
    printVector(s1);
    std::cout<<"Products of second array: "<<'\n';
    printVector(s2);
    
    return 0;
}