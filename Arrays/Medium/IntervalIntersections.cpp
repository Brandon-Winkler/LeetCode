#include<iostream>
#include<vector>
using namespace std;

// utility function for printing intersections
void printIntersections(const vector<vector<int>>& intersections){
    for(const auto& vec : intersections){
        cout<<"[ ";
        for(int n : vec){
            cout<<n<< " ";
        }
        cout<<"], ";
    }
    cout<<'\n';
}

    