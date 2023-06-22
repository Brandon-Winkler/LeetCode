#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        // initialize frequency map and variables
        std::map<int, int> freqMap;
        int count = 1, duplicate = 0;
        // loop through nums vector
        for(int i = 0; i < nums.size(); ++i) {
            // find number in map
            auto found = freqMap.find(nums[i]);
            // if number found twice return that number
            if(found != freqMap.end()) {
                found->second += 1;
                duplicate = found->first;
            }
            // else insert number and it's count into frequency map
            freqMap[nums[i]] = count;
        }
        // return duplicate number
        return duplicate;
    }
};

int main() {
    // make vector of ints
    std::vector<int> vec = {8,9,10,9,7,6,3,4,5};

    // create instance of class
    Solution Solution;
    
    // print solution
    std::cout << Solution.findDuplicate(vec) << '\n';

    return 0;
}