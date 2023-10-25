#include<iostream>
#include<vector>
using namespace std;

// utility function for printing intersections
void printIntersections(const vector<vector<int>>& intersections){
    if(intersections.empty()) cout<<"[]";
    for(const auto& vec : intersections){
        cout<<"[ ";
        for(int n : vec){
            cout<<n<< " ";
        }
        cout<<"], ";
    }
    cout<<'\n';
}

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()) return {{}};// if there is an empty vector return and empty set of intervals

        vector<vector<int>> ans;                                // answer vector for output
        int i = 0;                                              // first pointer for first list
        int j = 0;                                              // second pointer for second list
        cout<<"Am I reaching this part?";
        while(i<firstList.size() && j<secondList.size()){       // loop through both lists at the same time
            int l = max(firstList[i][0], secondList[j][0]);     // find the max between the two lists at beginning of their repective ranges
            int r = min(firstList[i][1], secondList[j][1]);     // find the min between the two lists at the end of their respective ranges
            if(l <= r) ans.push_back({l,r});                    // if the max of the beginning of the ranges is less than the min and the end of their ranges then push the max and min onto output vector
            if(firstList[i][1] > secondList[j][1]){             // if the end of the range if the first list is larger than the end of the range of the second list
                ++j;                                            // increment second pointer to find higher range for first list
            }
            else{
                ++i;                                            // otherwise increment first pointer to find higher range for second list
            }
        }
        return ans;
    }
};

// driver program
int main(){
    // initialze intervals
    vector<vector<int>> i1 = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> i2 = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> i3 = {{}};
    vector<vector<int>> i4 = {{4,7},{8,9},{10,11},{13,15},{16,20}};
    vector<vector<int>> i5 = {{1,5},{6,11},{12,13},{14,17},{18,19},{20,22}};

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.intervalIntersection(i1,i2);
    vector<vector<int>> s2 = Solution.intervalIntersection(i1,i3);
    vector<vector<int>> s3 = Solution.intervalIntersection(i4,i5);

    // outputs
    cout<<"The intersections of the first and second intervals are: ";
    printIntersections(s1);
    cout<<'\n';

    cout<<"The intersections of the first and third intervals are: ";
    printIntersections(s2);
    cout<<'\n';

    cout<<"The intersections of the fourth and fifth intervals are: ";
    printIntersections(s3);
    cout<<'\n';

    return 0;
}

    