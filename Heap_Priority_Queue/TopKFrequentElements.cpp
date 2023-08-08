#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> res; // initialize result vector for output
        std::unordered_map<int, int> map; // initialize frequency map for keeping track of how many times a number repeats

        for(int i=0;i<nums.size();++i) map[nums[i]]++; // loop through nums vector and update frequency map

        // initialize min priority que to access top most frequent elements
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for(const auto &pair : map){ // loop through frequency map
            pq.push({pair.second, pair.first}); // push the frequency first then the number
            if(pq.size() > k) pq.pop(); // if the size of the queue becomes greater than the k then pop from it so that we only have the k most frequent elements in the que
        }
        while(!pq.empty()){ // loop through priority queue
            // push numbers from queue into result vector and pop until queue is empty
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

// Utility fuction to print vector
void printVector(std::vector<int> v) {
    std::cout<<"[";
    for(int i=0;i<v.size();++i){
        std::cout<<" "<<v[i]<<" ";
    }
    std::cout<<"]"<<'\n';
}

int main(){
    // initialize vectors of integers
    std::vector<int> nums1{1,1,1,2,2,3};
    std::vector<int> nums2{3,3,4,4,4,4,8,8,8,1,2};
    std::vector<int> nums3{1};

    // solution class instance
    Solution Solution;

    // find k most frequent elements
    std::vector<int> res1 = Solution.topKFrequent(nums1, 2);
    std::vector<int> res2 = Solution.topKFrequent(nums2, 3);
    std::vector<int> res3 = Solution.topKFrequent(nums3, 1);

    // outputs
    std::cout<<"Most frequent elements in nums1: "<<'\n';
    printVector(res1);

    std::cout<<"Most frequent elements in nums2: "<<'\n';
    printVector(res2);

    std::cout<<"Most frequenct elements in nums3: "<<'\n';
    printVector(res3);

    return 0;
}
