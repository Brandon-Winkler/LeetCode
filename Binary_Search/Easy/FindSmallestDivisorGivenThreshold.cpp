#include<iostream>
#include<vector>

class Solution {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int l = 1;                                              // one will be our lower bound
        int r = *std::max_element(nums.begin(), nums.end());    // max in array is upper bound
        int ans = 1;                                            // smallest possible divisor

        while(l <= r){                                          // binary search divisors using one and max
            int m = l + (r-l) / 2;                              // create divisor
            long long sum = 0;                                  // initialize current sum
            for(int j=0;j<nums.size();++j){                     // sum up the quotient of all the numbers added to divisor minus one and the divisor itself 
                sum += (nums[j] + m - 1) / m;
            }
            if(sum <= threshold){                               // if the sum is less than or equal to the threshold then set answer to divisor and search left
                ans = m;
                r = m-1;
            }
            else{                                               // otherwise search right
                l = m+1;
            }
        }
        return ans;                                             // return smallest possible divisor
    }
};

// driver program
int main(){
    // intialize vectors
    std::vector<int> v1 = {1,2,5,9};
    std::vector<int> v2 = {44,22,33,11,1};
    std::vector<int> v3 = {21212,10101,12121};

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The smallest divisor given 6 as the threshold is "<<Solution.smallestDivisor(v1,6)<<'\n';
    std::cout<<"The smallest divisor given 5 as the threshold is "<<Solution.smallestDivisor(v2,5)<<'\n';
    std::cout<<"The smallest divisor given 1000000 as the threshold is "<<Solution.smallestDivisor(v3,1000000)<<'\n';
    return 0;
}