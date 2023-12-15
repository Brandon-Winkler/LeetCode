#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int lhs = 0, rhs = nums.size() - 1, mid = (nums.size() - 1) / 2;

        while(lhs <= rhs) {
            // reinitialize midpoint
            mid = (rhs+lhs) / 2;

            if(nums[lhs] == target) return lhs;
            if(nums[mid] == target) return mid;
            if(nums[rhs] == target) return rhs;

            // left portion of array
            if(nums[lhs] <= nums[mid]) {
                if(nums[lhs] <= target && target <= nums[mid]) {
                    rhs = mid - 1;
                }
                else { 
                    lhs = mid + 1;
                }
            }
            // right portion of array
            else {
                if(nums[mid] <= target && target <= nums[rhs]) {
                    lhs = mid + 1;
                }
                else {
                    rhs = mid - 1;
                }
            } 
        }
        return -1;
    }
};

int main() {

    // initialize rotated array
    std::vector<int> arr = {4,5,6,7,8,1,2,3};

    // class instance
    Solution Solution;

    // output
    std::cout << Solution.search(arr, 8) << '\n';

    return 0;
}