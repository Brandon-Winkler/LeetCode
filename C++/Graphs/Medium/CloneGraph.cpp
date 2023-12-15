#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
    }
};

// driver program
int main(){
    // initialize graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    node1->neighbors = {node2, node3, node6};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1, node2, node5};
    node4->neighbors = {node5, node4, node3};
    node5->neighbors = {node1, node4};
    node6->neighbors = {node1, node2, node3};

    // solution class instance
    Solution Solution;

    Node* sol = Solution.cloneGraph(node1);

    return 0;
}