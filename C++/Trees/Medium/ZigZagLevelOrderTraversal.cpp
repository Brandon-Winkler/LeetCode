#include <vector>
#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        // initialize result for output and queue for BFS
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> que;

        if(root == nullptr) return res; // if root is null return empty vector

        que.push(root); // push root to begin BFS
        int level = 0; // initialize level to 0 to keep track of all even and odd levels

        while(!que.empty()) { // begin BFS
            std::vector<int> vec; // initialize subvector to push levels values into
            int levelSize = que.size(); // initialize level size to loop through current queue size
            for(int i = 0; i < levelSize; ++i) {
                TreeNode *node = que.front(); // create node pointer to front of queue
                que.pop(); // pop from queue to continue traversal
                if(node != nullptr) { // if node is not null push value into subvector and push left and right nodes into queue
                    vec.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if(level % 2 != 0) std::reverse(vec.begin(), vec.end()); // if level is odd reverse subvector
            if(!vec.empty()) res.push_back(vec); // if subvector isn't empty push it into result
            ++level; // increment level
        }
        return res;
    }
};

// Utility fuction to print vector
void printVector(std::vector<std::vector<int>> v) {
    for (const auto& innerVec : v) {
        for (const auto& element : innerVec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

int main() {
    // initialize tree
    TreeNode* root = createTreeNode(5);
    root->right = createTreeNode(10);
    root->left = createTreeNode(0);
    root->left->left = createTreeNode(-1);
    root->left->right = createTreeNode(2);
    root->left->right->left = createTreeNode(1);
    root->right->left = createTreeNode(6);
    root->right->left->right = createTreeNode(7);
    root->right->right = createTreeNode(12);

    // solution class instance and result vector
    Solution Solution;
    std::vector<std::vector<int>> res = Solution.zigzagLevelOrder(root);

    // output
    printVector(res);
    
    return 0;
}

