#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> ans = nums; // initialize result vector to vector passed into the function
        for(int i=0;i<nums.size();++i){ // loop through nums
            ans.push_back(nums[i]); // push back each value into result vector
        }
        return ans;
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

int main(){
    // initialize vectors
    std::vector<int> first = {1,2,1};
    std::vector<int> second = {1,3,2,1};

    // solution class instance
    Solution Solution;

    std::vector<int> s1 = Solution.getConcatenation(first);
    std::vector<int> s2 = Solution.getConcatenation(second);

    // output
    std::cout<<"Concatination of first: "<<'\n';
    printVector(s1);

    std::cout<<"Concatination of second: "<<'\n';
    printVector(s2);

    return 0;
}