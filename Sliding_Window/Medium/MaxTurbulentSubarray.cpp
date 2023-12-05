#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr){
        int l = 0, r = 1;                                   // initialize left and right pointers for window
        string sign = "";                                   // set sign initially to be empty
        int ans = 1;                                        // set answer to one to account for ith starting position

        while(r<arr.size()){                                // loop through array as long as right side of window is inbounds
            if(arr[r-1] > arr[r] && sign != ">"){           // if the value to the left of right side is greater than and sign is greater than
                ans = max(ans, r-l+1);                      // set answer to max of answer and right minus left plus one
                r++;                                        // increment right side
                sign = ">";                                 // set sign to be greater than
            }
            else if(arr[r-1] < arr[r] && sign != "<"){      // if the value to the left of the right side is less than and sign is less than 
                ans = max(ans, r-l+1);                      // set answer to max of answer and right minus left plus one
                r++;                                        // increment right side
                sign = "<";                                 // set sign to less than
            }
            else{                                           // otherwise don't set answer to anything
                if(arr[r-1] == arr[r]) r++;                 // if value to the left is equal to right side then increment r
                l = r-1;                                    // set left side to the left of the right side
                sign = "";                                  // set sign to empty
            }
        }
        return ans;
    }
};

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {9,4,2,10,7,8,8,1,9};
    vector<int> v2 = {4,8,12,16};
    vector<int> v3 = {100};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The maximum length of the longest turbulent subarray in array 1 is "<<Solution.maxTurbulenceSize(v1)<<'\n';
    cout<<"The maximum length of the longest turbulent subarray in array 2 is "<<Solution.maxTurbulenceSize(v2)<<'\n';
    cout<<"The maximum length of the longest turbulent subarray in array 3 is "<<Solution.maxTurbulenceSize(v3)<<'\n';
    return 0;
}