#include<unordered_map>
#include<vector>
#include<iostream>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map;                                        // map to keep track of values and their indices

        for(int i=0;i<nums.size();++i){                                         // loop through nums to find duplicate
            if(map.find(nums[i]) != map.end() && i - map[nums[i]] <= k){        // if value at index i is in map and i minus the current index of previous value is less than or equal to k return true
                return 1;
            }
            else{                                                               // otherwise update the value of key in map with current index
                map[nums[i]] = i;
            }
        }
        return 0;                                                               // if we finish the loop return false
    }
};

// driver program
int main(){
    // intialize arrays
    std::vector<int> v1 = {1,2,3,1,2,3};
    std::vector<int> v2 = {5,4,8,3,4,4,3,11};
    std::vector<int> v3 = {4,3,5,2};

    // solution class instance
    Solution Solution;

    bool s1 = Solution.containsNearbyDuplicate(v1,3);
    bool s2 = Solution.containsNearbyDuplicate(v2,1);
    bool s3 = Solution.containsNearbyDuplicate(v3,2);

    //outputs
    if(s1){
        std::cout<<"The first array does have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }
    else{
        std::cout<<"The first array doesn't have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }

    if(s2){
        std::cout<<"The second array does have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }
    else{
        std::cout<<"The second array doesn't have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }

    if(s3){
        std::cout<<"The third array does have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }
    else{
        std::cout<<"The third array doesn't have two distinct indices whos absolute difference is less than or equal to the provided integer"<<'\n';
    }
    return 0;
}