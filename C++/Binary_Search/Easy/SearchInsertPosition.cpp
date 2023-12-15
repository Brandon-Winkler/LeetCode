#include <vector>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size(); // initialize left and right pointers
        if(nums[r-1] < target) return r; // return right if target is greater than last index

        while(l <= r){ // loop while left is less than or equal to right
            int m = (r+l)/2; // initialize midpoint
            if(nums[m] == target){ // if value at midpoint is equal to target
                return m; // return midpoint index
            } 
            else if(nums[m] < target){ // if target is greater than value at midpoint
                l = m+1; // then search right
            }
            else{
                r = m-1; // otherwise search left
            }
        }
        return l; // if right becomes less than left loop will break and return left index
    }
};

int main() {
    // initialize vectors
    std::vector<int> vec1 = {1,3,5,6};
    std::vector<int> vec2 = {1,2,3,5,7,9};

    // initialize variables
    int five = 5, ten = 10, eight = 8, zero = 0;

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"Insert position for 5 in vector 1 is: "<<Solution.searchInsert(vec1, five)<<'\n';
    std::cout<<"Insert position for 10 in vector 1 is: "<<Solution.searchInsert(vec1, ten)<<'\n';
    std::cout<<"Insert position for 8 in vector 2 is: "<<Solution.searchInsert(vec2, eight)<<'\n';
    std::cout<<"Insert position for 0 in vector 2 is: "<<Solution.searchInsert(vec2, zero)<<'\n';
    
    return 0;
}

