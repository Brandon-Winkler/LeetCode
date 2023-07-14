#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        
        // left and right side
        int lhs = 0, 
            rhs = nums.size() - 1; 

        while(lhs <= rhs) {

            // readjust middle of array
            int mid = (rhs + lhs) / 2;
            
            // search right
            if( nums[mid] < target ) {
                lhs = mid + 1;
            }

            // search left
            else if( nums[mid] > target ) {
                rhs = mid - 1;
            }

            // if we find the target
            else {
                if( nums[lhs] != target ) {
                    ++lhs;
                }
                else if( nums[rhs] != target ) {
                    --rhs;
                }
                else {
                    return {lhs,rhs}; // return target range
                }
            }
        }
        return {-1,-1}; // target range found
    }
};

int main() {

    // vector to be searched
    std::vector<int> vec = {1,2,3,4,5,6,6,6,6,7};

    // search for 6:
    int six = 6;

    // solution class
    Solution Solution;
    std::vector<int> result = Solution.searchRange(vec,six);

    // output
    std::cout << "Six occurs in the range: [";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << " " << result[i] << " ";
    }
    std::cout << ']' << '\n';
    
    return 0;
 }