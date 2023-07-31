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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> rsv; // initialize right side view vector for output
        if(root == nullptr) return rsv; // if root is empty return empty vector

        std::queue<TreeNode *> que; // make a queue for level order traversal
        que.push(root); // push the root to begin traversal

        while(!que.empty()) {
            int levelSize = que.size(); // level size so that we can only push what is in each level

            // loop through the queue "levelSize" times
            for(int i = levelSize; i > 0; --i) {

                TreeNode *node = que.front(); // create node pointer to front of queue
                que.pop(); // pop from queue to continue traversal

                if(i == levelSize) rsv.push_back(node->val); // push node value of right most node
                if(node->right != nullptr) que.push(node->right); // push right node onto queue
                if(node->left != nullptr) que.push(node->left); // push left node onto queue
            }
        }
        return rsv;
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

// Utility fuction to print vector
void printVector(std::vector<int> v) {
    std::cout << "[";
    for(int i = 0; i < v.size(); ++i) {
        std::cout << " " << v[i] << " ";
    }
    std::cout << "]" << '\n';
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
    std::vector<int> res = Solution.rightSideView(root);

    // print output
    printVector(res);

    return 0;
}