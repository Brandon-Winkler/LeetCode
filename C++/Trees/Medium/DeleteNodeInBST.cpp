#include <iostream>
#include <queue>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root; // if root is null then return the root

        if(key > root->val){ // case where key is in right subtree if so go right
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val){ // case where key is in left subtree if so go left
            root->left = deleteNode(root->left, key);
        }
        else{ // case where we found our node with the key
            if(root->left == nullptr) return root->right;       // if node has no left child then return the right child
            else if(root->right == nullptr) return root->left;  // if node has no right child the return the left child

            // case where node with key has both left and right children
            TreeNode *node = root->right;                       // pointer to keep track of successor, go right first
            while(node->left != nullptr) node = node->left;     // then go left until you can't go left anymore
            root->val = node->val;                              // assign successor node value to value of node we found
            root->right = deleteNode(root->right, root->val);   // call deleteNode on right subtree recursively to delete successor node
        }
        return root;
    }
};

// Utility function for printing the tree in level order
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

int main(){
    // initialize tree
    TreeNode *root=createTreeNode(5);
    root->right=createTreeNode(10);
    root->left=createTreeNode(0);
    root->left->left=createTreeNode(-1);
    root->left->right=createTreeNode(2);
    root->left->right->left=createTreeNode(1);
    root->right->left=createTreeNode(6);
    root->right->left->right=createTreeNode(7);
    root->right->right=createTreeNode(12);

    // solution class instance
    Solution Solution;

    std::cout<<"Tree before deletions: "<<'\n';
    printTreeLevelOrder(root);
    std::cout<<'\n';

    Solution.deleteNode(root, 0);
    std::cout<<"Tree after deleting 0: "<<'\n';
    printTreeLevelOrder(root);
    std::cout<<'\n';

    Solution.deleteNode(root, 6);
    std::cout<<"Tree after deleting 6: "<<'\n';
    printTreeLevelOrder(root);
    std::cout<<'\n';

    Solution.deleteNode(root, 5);
    std::cout<<"Tree after deleting 5: "<<'\n';
    printTreeLevelOrder(root);
    std::cout<<'\n';

    return 0;
}

