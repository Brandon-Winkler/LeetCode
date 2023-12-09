#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
    }
};

// driver program
int main(){
    // initialize arrays
    vector<int> flowerBed = {1,0,0,0,1};

    // solution class instance
    Solution Solution;

    bool canPlace1 = Solution.canPlaceFlowers(flowerBed, 1);
    bool canPlace2 = Solution.canPlaceFlowers(flowerBed, 2);

    // output
    if(canPlace1) cout<<"You can place all the flowers in the flowerbed."<<'\n';
    else cout<<"You cannot place all the flowers in the flowerbed"<<'\n';

    if(canPlace2) cout<<"You can place all the flowers in the flowerbed."<<'\n';
    else cout<<"You cannot place all the flowers in the flowerbed"<<'\n';
    return 0;
}