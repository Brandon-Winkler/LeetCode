#include<queue>
#include<iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> pQue;         // initialze que to traverse first tree
        std::queue<TreeNode*> qQue;         // initialize que to traverse second tree

        pQue.push(p);                       // push to first que to begin bfs on first tree
        qQue.push(q);                       // push to second que to begin bfs on second tree

        while(!pQue.empty() && !qQue.empty()){  // loop through both ques
            TreeNode* node1 = pQue.front();     // set current node to first que front for processing
            TreeNode* node2 = qQue.front();     // set current node to second que front for processing 
            pQue.pop();                         // pop from first que to mark that we have seen node in first tree
            qQue.pop();                         // pop from second que to mark that we have seen node in second tree

            if(node1 == nullptr && node2 == nullptr) continue;                              // if both are null then do nothing and continue
            if(node1 == nullptr || node2 == nullptr || node1->val != node2->val) return 0;  // if only one is null or their values don't match then return false

            pQue.push(node1->left);     // push first trees left child 
            pQue.push(node1->right);    // push first trees right child 
            qQue.push(node2->left);     // push second trees left child
            qQue.push(node2->right);    // push second trees right child
        }
        return 1; // if we were able to traverse through both trees completely return true
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

// driver program
int main(){
    // initialize trees
    TreeNode* root = createTreeNode(5);
    root->right = createTreeNode(10);
    root->left = createTreeNode(0);
    root->left->left = createTreeNode(-1);
    root->left->right = createTreeNode(2);
    root->left->right->left = createTreeNode(1);
    root->right->left = createTreeNode(6);
    root->right->left->right = createTreeNode(7);
    root->right->right = createTreeNode(12);

    TreeNode* root2 = createTreeNode(5);
    root2->right = createTreeNode(10);
    root2->left = createTreeNode(0);
    root2->left->left = createTreeNode(-1);
    root2->left->right = createTreeNode(2);
    root2->left->right->left = createTreeNode(1);
    root2->right->left = createTreeNode(6);
    root2->right->left->right = createTreeNode(7);
    root2->right->right = createTreeNode(12);

    TreeNode* root3 = createTreeNode(5);
    root3->right = createTreeNode(10);
    root3->left = createTreeNode(0);
    root3->left->left = createTreeNode(-2);
    root3->left->right = createTreeNode(3);
    root3->left->right->left = createTreeNode(1);
    root3->right->left = createTreeNode(6);
    root3->right->left->right = createTreeNode(7);

    // solution class instance
    Solution Solution;

    bool s1 = Solution.isSameTree(root, root2);
    bool s2 = Solution.isSameTree(root, root3);

    // outputs
    if(s1){
        std::cout<<"Tree one is the same as tree two."<<'\n';
    }
    else{
        std::cout<<"Tree one and tree two are not the same."<<'\n';
    }

    if(s2){
        std::cout<<"Tree one is the same as tree three."<<'\n';
    }
    else{
        std::cout<<"Tree one and tree three are not the same."<<'\n';
    }
    
    return 0;
}