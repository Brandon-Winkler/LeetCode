#include <queue>
#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
        // if root is null return the root
        if(root == nullptr) return root;

        // initialize queue for BFS and push root into queue to start
        std::queue<TreeNode *> que;
        que.push(root);

        // while the queue isn't empty do BFS and swap the left and right nodes after popping from the queue
        while(!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            std::swap(cur->left, cur->right);
            if(cur->left != nullptr) que.push(cur->left);
            if(cur->right != nullptr) que.push(cur->right);
        }
        return root;
    }
};

// utility function for printing the tree in level order
void printTreeLevelOrder(TreeNode *root) {
    if (root == nullptr) return;

    std::queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode *cur = queue.front();
        queue.pop();
        std::cout << cur->val << " ";
        if (cur->left) queue.push(cur->left);
        if (cur->right) queue.push(cur->right);
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

    std::cout << "Tree before inversion: " << '\n';
    printTreeLevelOrder(root);
    std::cout << '\n';

    // solution class instance and method
    Solution Solution;
    Solution.invertTree(root);

    std::cout << "Tree after inversion: " << '\n';
    printTreeLevelOrder(root);
    std::cout << '\n';

    return 0;
}