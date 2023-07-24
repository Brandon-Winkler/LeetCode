#include <vector>
#include <iostream>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        // initialize left, right and mid iterators
        int l = 0, r = nums.size() - 1, m = l + (r - l) / 2;

        // loop through nums
        while(l <= r) {
            // reinitialize midpoint
            m = l + (r - l) / 2;

            // go left if left neighbor is greater
            if(m > 0 && nums[m] < nums[m - 1]) {
                r = m - 1;
            }
            // got right if right neighbor is greater
            else if(m < nums.size() - 1 && nums[m] < nums[m + 1]) {
                l = m + 1;
            }
            // return m when element on either side is greater
            else {
                return m;
            }
        }
        return m;
    }
};

int main() {
    // initialize array
    std::vector<int> v = {37,0,17,68,0,68,78,0,44,53};

    // solution class instance
    Solution Solution;

    // output
    std::cout << Solution.findPeakElement(v) << '\n';

    return 0;
}