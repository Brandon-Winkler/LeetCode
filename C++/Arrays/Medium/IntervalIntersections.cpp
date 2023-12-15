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
        cout<<"]";
    }
    cout<<'\n';
}

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;                                // answer vector for output
        int i = 0;                                              // first pointer for first list
        int j = 0;                                              // second pointer for second list

        while(i<firstList.size() && j<secondList.size()){       // loop through both lists at the same time
            int l = max(firstList[i][0], secondList[j][0]);     // find the max between the two lists at beginning of their repective ranges
            int r = min(firstList[i][1], secondList[j][1]);     // find the min between the two lists at the end of their respective ranges

            if(l <= r){                                         // if left is less than or equal to right
                ans.push_back({l,r});                           // push left and right onto output vector
                if(r == firstList[i][1]) ++i;                   // if right is less equal to the end of the first range then increment first list pointer
                else ++j;                                       // otherwise increment the second range pointer
            }
            else{                                               // if right is greater than left
                if(firstList[i][0] > secondList[j][1]) ++j;     // if beginning of first range is greater than end of second range increment second list pointer
                else if(secondList[j][0] > firstList[i][1]) ++i; // if beginning of second range is greater than the end of the first range increment first list pointer
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
    vector<vector<int>> i3 = {{4,7},{8,9},{10,11},{13,15},{16,20}};
    vector<vector<int>> i4 = {{1,5},{6,11},{12,13},{14,17},{18,19},{20,22}};

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.intervalIntersection(i1,i2);
    vector<vector<int>> s2 = Solution.intervalIntersection(i3,i4);

    // outputs
    cout<<"The intersections of the first and second intervals are: ";
    printIntersections(s1);
    cout<<'\n';

    cout<<"The intersections of the third and fourth intervals are: ";
    printIntersections(s2);
    cout<<'\n';

    return 0;
}

    