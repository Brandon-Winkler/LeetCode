#include<map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> map;                                   // initialize frequency map

        for(int n=0;n<nums.size();++n) ++map[nums[n]];      // create frequency table

        auto it = map.begin();                              // set iterator to begin loop
        int maj = it->first;                                // set majority element to first key
        int val = it->second;                               // set current value to value of first key

        while(it != map.end()){                             // loop until end of map
            if(it->second > val){                           // if the value in loop is greater than current value
                maj = it->first;                            // update majority to key in loop
                val = it->second;                           // update current value to value in loop
            }
            ++it;                                           // continue iteration through map
        }
        return maj;
    }
};

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {2,2,1,3,4,3,3,3,6};
    vector<int> v2 = {0,2,0,0,0,1};
    vector<int> v3 = {10};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The majority element int vector 1 is: "<<Solution.majorityElement(v1)<<'\n';
    cout<<"The majority element int vector 2 is: "<<Solution.majorityElement(v2)<<'\n';
    cout<<"The majority element int vector 3 is: "<<Solution.majorityElement(v3)<<'\n';
    
    return 0;
}
