#include<iostream>

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;                      // lower bound
        int r = x;                      // upper bound
        int ans = 0;                    // initialize answer variable

        while(l <= r){                  // loop through bounds
            long long m = (r+l) / 2;    // set mid point on each loop
            if((m*m) > x){              // if m * m is greater than x search left
                r = m-1;
            }
            else if((m*m) < x){         // if m * m is less than x search left and set answer to midpoint
                l = m+1;
                ans = m;
            }
            else{
                return m;               // if m * m is equal to x then return midpoint
            }
        }
        return ans;                     // return answer variable
    }
};

// driver program
int main(){
    // squares
    int x = 9;
    int y = 100;
    int z = 13;

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"Square root of "<<x<<" is "<<Solution.mySqrt(x)<<'\n';
    std::cout<<"Square root of "<<y<<" is "<<Solution.mySqrt(y)<<'\n';
    std::cout<<"Closest Square root of "<<z<<" is "<<Solution.mySqrt(z)<<'\n';

    return 0;
}