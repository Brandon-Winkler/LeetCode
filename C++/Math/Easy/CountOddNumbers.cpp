#include<iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;                          // count variable for output
        if(low%2 == 0) ++low;                   // if we are starting at an even number increase to an odd one
        for(int i=low;i<=high;i+=2) ++count;    // add one for every odd number we see
        return count;                           // return count for odd numbers
    }
};

int main(){
    // solution class instance
    Solution Solution;

    // output
    cout<<"There are "<<Solution.countOdds(3,7)<<" odd numbers between 3 and 7."<<'\n';
    cout<<"There are "<<Solution.countOdds(6,22)<<" odd numbers between 6 and 22."<<'\n';
    return 0;
}