#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end()); // initialize set to keep track of beginnings of sequences
        int longest = 0;                                       // initialize longest to zero to begin tracking sequences
        for(auto &n : set){                                    // loop through set
            if(!set.count(n - 1)){                             // if the number in set has not left neighbor
                int length = 1;                                // set length variable to one to begin sequence
                while(set.count(n + length))                   // while n in set has a right neighbor
                    ++length;                                  // add one to length to keep track of the sequence length
                longest = std::max(longest, length);           // compare the sequences length to longest we have found so far and set longest to highest between longest and length
            } 
        }
        return longest;
    }
};

// Driver program
int main(){
    // initialize vectors
    std::vector<int> v1 = {100,4,200,1,3,2};
    std::vector<int> v2 = {0,3,7,2,5,8,4,6,0,1};

    // solution class
    Solution Solution;

    //output
    std::cout<<"The longest consecutive sequence for vector one has a length of: "<<Solution.longestConsecutive(v1)<<'\n';
    std::cout<<"The longest consecutive sequence for vector two has a length of: "<<Solution.longestConsecutive(v2)<<'\n';
    return 0;
}

