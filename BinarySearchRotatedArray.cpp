#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {

        // initialize variables list: right, left, mid, min
        int lhs = 0, 
            rhs = nums.size() - 1, 
            mid = (nums.size() - 1) / 2,
            min = nums[mid];

        // if nums are empty return NULL
        if(nums.empty()) return 0;

        // loop through array to find the smallest element
        while(lhs <= rhs) {

            if(nums[rhs] > nums[mid]) {
                rhs = mid - 1;
                mid = (rhs + lhs) / 2;
            } else {
                lhs = mid + 1;
                mid = (rhs + lhs) / 2;
            }

            if(min > nums[mid]) min = nums[mid];
        }

        //return smallest element
        return min;
    }
};

int main() {

    // initialize vector
    std::vector<int> list = {4,5,6,7,1,3};

    // create class instance
    Solution Solution;

    // print results
    std::cout << Solution.findMin(list) << '\n';

    return 0;
}