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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if root is null then insert new value at root and return
        if(root == nullptr) {
            return root = new TreeNode(val);
        }
        
        TreeNode *node = root; // create node pointer to keep track of current node

        while(node != nullptr) { // loop through tree
            if(val < node->val && node->left != nullptr) node = node->left; // go left if value is less than current node value and current node is not a leaf
            if(val > node->val && node->right != nullptr) node = node->right; // go right if value is less that current node value and current node is not a leaf
            if(val < node->val && node->left == nullptr) { // if value is less than current node value and current node is a leaf insert at left
                node->left = new TreeNode(val);
                break; 
            }
            if(val > node->val && node->right == nullptr) { // if value is greater than current node value and current node is a leaf insert at right
                node->right = new TreeNode(val);
                break;
            }
        }
        return root;
    }
};

// Function for printing each level of the tree
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            std::cout << currentNode->val << " ";

            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
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

    std::cout << "Tree before insertions: " << '\n';
    printLevelOrder(root);

    // solution class instance and insertions
    Solution Solution;
    Solution.insertIntoBST(root, 3);
    Solution.insertIntoBST(root, 8);

    std::cout << "Tree after insertions: " << '\n';
    printLevelOrder(root);

    return 0;
}

