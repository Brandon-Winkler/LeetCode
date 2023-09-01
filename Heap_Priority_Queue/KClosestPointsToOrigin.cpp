#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <math.h>

class Solution {
private:
    float distance(int x, int y){ // create helper function for distance formula
        return sqrt(pow(x-0, 2) + pow(y-0, 2));
    }
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::vector<std::vector<int>> ans; // vector for output
        std::priority_queue<std::pair<float, int>> pq; // max priority queue to keep track of closest points
        std::pair<float, int> dist; // pair for distance number and distance index

        for(int i=0;i<points.size();++i){ // begin loop through points
            dist.first = distance(points[i][0], points[i][1]); // set distance of point into first of dist
            dist.second = i; // set associated index of point to second of dist
            pq.push(dist); // push pair into priority queue
            if(pq.size() > k) pq.pop(); // if priority queue becomes larger than k pop top (max pair)
        }

        while(!pq.empty()){ // while max priority queue isn't empty
            ans.push_back(points[pq.top().second]); // push the element in points that whose index matches the second value of the top pair
            pq.pop(); // pop from max priority queue
        }
        return ans;
    }
};

// Function to print points
void printPoints(const std::vector<std::vector<int>>& vec) {
    for (const auto& point : vec) {
        std::cout << "(" << point[0] << ", " << point[1] << ")" << std::endl;
    }
}

int main() {
    // initialize points
    std::vector<std::vector<int>> g1 = {{3,3},{5,-1},{-2,3}};
    std::vector<std::vector<int>> g2 = {{6,3},{-2,-1},{5,4},{4,-4},{-7,1},{8,8}};
    std::vector<std::vector<int>> g3 = {{0,-100},{-100,0},{10,10},{34,43}};

    // solution class instance
    Solution Solution;

    // solution variables
    std::vector<std::vector<int>> s1 = Solution.kClosest(g1, 2);
    std::vector<std::vector<int>> s2 = Solution.kClosest(g2, 3);
    std::vector<std::vector<int>> s3 = Solution.kClosest(g3, 2);

    // output
    std::cout<<"The 2 closest points for g1 are:"<<'\n';
    printPoints(s1);
    std::cout<<"The 3 closest points for g2 are:"<<'\n';
    printPoints(s2);
    std::cout<<"The 2 closest points for g3 are:"<<'\n';
    printPoints(s3);
    
    return 0;
}