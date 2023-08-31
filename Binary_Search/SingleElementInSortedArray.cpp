#include <vector>
#include <iostream>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int l = 0, r = nums.size()-1; // initialize left and right pointers to beginning and end of array

        while(l<r){ // loop until left is greater than right
            int m = (r+l)/2; // calculate midpoint
            if(m%2 == 1){ // if midpoint index is odd decrement by 1 so that midpoint is an even index
                --m;
            }
            if(nums[m] != nums[m+1]){ // if value at midpoint index is not equal to the value at index to the right search left
               r = m;
            }
            else{ // if value at midpoint index is equal to the value at index to the right search right
                l = m+2;
            }
        }
        return nums[l];
    }
};

int main() {
    // initialize vectors
    std::vector<int> vec1 = {1,1,2,3,3,4,4,8,8};
    std::vector<int> vec2 = {3,3,7,7,10,11,11};
    std::vector<int> vec3 = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,9,9,10,10};
    std::vector<int> vec4 = {1,2,2};

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The single number in vector 1 is: "<<Solution.singleNonDuplicate(vec1)<<'\n';
    std::cout<<"The single number in vector 2 is: "<<Solution.singleNonDuplicate(vec2)<<'\n';
    std::cout<<"The single number in vector 3 is: "<<Solution.singleNonDuplicate(vec3)<<'\n';
    std::cout<<"The single number in vector 4 is: "<<Solution.singleNonDuplicate(vec4)<<'\n';
    
    return 0;
}