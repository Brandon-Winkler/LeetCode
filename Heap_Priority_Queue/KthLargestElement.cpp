#include <queue>
#include <iostream>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0]; // there is only one element in nums return that element

        std::priority_queue<int, std::vector<int>, std::greater<int>> minpq(nums.begin(), nums.begin() + k); // initialize min priority queue with beginning of vector up to kth value

        for(int i=k;i<nums.size();++i){ // set our first index at the kth value to loop through queue
            if(nums[i] > minpq.top()){ // if the value at i is greater than the minimum at top pop from queue and push the value at ith index
                minpq.pop();
                minpq.push(nums[i]);
            }
        }    
        return minpq.top(); 
    }
};

int main(){
    // initialize vectors and variables
    std::vector<int> first = {3,2,1,5,6,4};
    std::vector<int> second = {2,7,4,1,8,1};
    std::vector<int> third = {3,2,3,1,2,4,5,5,6};
    int k = 4, n = 5, j = 6; 

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The "<<k<<"th largest element in first is: "<<Solution.findKthLargest(first,k)<<'\n';
    std::cout<<"The "<<n<<"th largest element in second is: "<<Solution.findKthLargest(second,n)<<'\n';
    std::cout<<"The "<<j<<"th largest element in third is: "<<Solution.findKthLargest(third,j)<<'\n';
    
    return 0;
}


