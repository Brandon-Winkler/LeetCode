#include<set>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

class Solution{
public:
    vector<vector<int>> buildRoads(int cities, vector<vector<int>> roads){
        map<int, set<int>> nodeMap;                         // create a map to represent nodes and their connections
        vector<vector<int>> ans;                            // create a vector of vectors for missing edges
        
        for(int r=0;r<roads.size();r++){                    // loop through roads to create map of nodes and connections
            int node1 = roads[r][0];                        // set first node to first value in pair
            int node2 = roads[r][1];                        // set second node to second value in pair
            nodeMap[node1].insert(node2);                   // insert node 2 into value set of node 1
            nodeMap[node2].insert(node1);                   // insert node 1 into value set of node 2
        }
        for(auto const& e : nodeMap){                       // loop through map
            int node = e.first;                             // set current node to key
            set<int> edges = e.second;                      // set edges list as set value
            
            for(int i=0;i<cities;i++){                      // loop through cities
                if(i == node) continue;                     // if the current index is equal to the current node then do nothing
                else{
                    if(edges.find(i) == edges.end()){       // otherwise if we can't find the current index in the edge set
                        ans.push_back({node, i});           // then push the current node and index vector into answer output
                        nodeMap[node].insert(i);            // insert current index into value set of current node to create that connection
                        nodeMap[i].insert(node);            // insert current node into value set of current index to create the second connection
                    }
                }
            }
        }
        return ans;
    }
};

// Utility fuction to print vector of vectors
void printVectorOfVectors(const vector<vector<int>>& vec) {
    for(const vector<int>& innerVec : vec){
        cout<<"[ ";
        for(int num : innerVec){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
}

// driver program
int main(){
    // initialize roads
    vector<vector<int>> c1 = {
        {0,1},
        {1,2},
        {2,0}
    };
    vector<vector<int>> c2 = {
        {1,2},
        {0,2},
        {1,4},
        {4,2},
        {3,5},
        {1,0},
        {5,0},
        {3,1},
        {0,4},
        {5,1},
        {3,2},
        {3,0},
        {2,5}
    };

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.buildRoads(4, c1); 
    vector<vector<int>> s2 = Solution.buildRoads(6, c2); 

    // output
    cout<<"The roads that need to be built for city 1 are:"<<'\n';
    printVectorOfVectors(s1);
    cout<<'\n';

    cout<<"The roads that need to be built for city 2 are:"<<'\n';
    printVectorOfVectors(s2);
    cout<<'\n';
    return 0;
}

