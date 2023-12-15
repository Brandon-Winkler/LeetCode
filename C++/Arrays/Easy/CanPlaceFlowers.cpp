#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // if edge case where we have no flowers return true
        if(n == 0) return true;

        // insert zeros at beginning and end of flowerbed to avoid out of bounds
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

        // loop through flowerbed starting at 1 and go until the second to last element since we added zeros at front and back
        for(int i=1;i<flowerbed.size()-1;i++){
            // if there are no flowers behind, at or in front of the current index set value at i to 1 and subtract from n flowers
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            // if we have no more flowers return true
            if(n == 0) return true;
        }
        // return false if we have flowers still
        return false;
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