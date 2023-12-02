#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, ans = 0;               // initialize sum to 0 to keep track of current window sum and answer to 0 to count number of windows
        int l = 0, r = k;                   // initialize left and right side of window

        for(int i=0;i<k;++i) sum += arr[i]; // add up all the numbers in the current window
        if(sum/k >= threshold) ++ans;       // if the average of the numbers in the current window is less than or equal to the threshold add one to output

        while(r < arr.size()){              // loop through array until right side is out of bounds
            sum -= arr[l++];                // subtract the next left value from sum and increment left side
            sum += arr[r++];                // add the next left value to sum and increment right side
            if(sum/k >= threshold) ++ans;   // if the current sum is greater than or equal to the threshold then add one to the count
        }
        return ans;
    }
};

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {2,2,2,2,5,5,5,8};
    vector<int> v2 = {11,13,17,23,29,31,7,5,2,3};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The number subarrays with size 3 and a threshold of 4 for vector 1 are: "<<Solution.numOfSubarrays(v1,3,4)<<'\n';
    cout<<"The number subarrays with size 3 and a threshold of 5 for vector 2 are: "<<Solution.numOfSubarrays(v2,3,5)<<'\n';
    return 0;
}