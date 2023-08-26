#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones){
        if(stones.size() == 1) return stones[0]; // return the only stone in the vector if size is 1
        if(stones.empty()) return 0; // return zero if vector is empty

        std::priority_queue<int> pq; // initialize heap
        for(int s=0;s<stones.size();++s) pq.push(stones[s]); // transfer stone values from vector to heap

        while(pq.size() > 1){ // loop through queue
            int max = pq.top();         // max variable to keep track of current max
            pq.pop();                   // pop priority queue to get the next max
            int dif = max - pq.top();   // difference variable to find difference of current and next max
            pq.pop();                   // pop priority queue to make room for difference variable
            pq.push(dif);               // push difference
        }
        return pq.top();
    }
};

int main(){
    // initialize vectors
    std::vector<int> first = {2,7,4,1,8,1};
    std::vector<int> second = {2};
    std::vector<int> third = {};

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"Last stone weight for first vector: "<<Solution.lastStoneWeight(first)<<'\n';
    std::cout<<"Last stone weight for second vector: "<<Solution.lastStoneWeight(second)<<'\n';
    std::cout<<"Last stone weight for third vector: "<<Solution.lastStoneWeight(third)<<'\n';
    return 0;
}


