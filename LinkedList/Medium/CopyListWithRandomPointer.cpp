#include <iostream>
#include <unordered_map>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Function to print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // Create a mapping of original nodes to their copies
        std::unordered_map<Node*, Node*> nodeMap;
        
        Node *curr = head;
        while (curr != nullptr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Assign next and random pointers for the copied nodes
        curr = head;
        while (curr != nullptr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        // Return the head of the copied list
        return nodeMap[head];
    }
};



int main() {

    // Create a linked list with random pointers
    Node *node1 = new Node(10);
    Node *node2 = new Node(3);
    Node *node3 = new Node(9);
    Node *node4 = new Node(5);
    //10 -> 3 -> 9 -> 5 -> NULL
    node1->next = node2;
    node1->random = NULL;
    node2->next = node3;
    node2->random = node4;
    node3->next = node4;
    node3->random = node1;
    node4->next = NULL;
    node4->random = node4;

    //Create solution class & copy list
    Solution Solution;
    Node *listCopy = Solution.copyRandomList(node1);

    //print original list
    std::cout << "Original list: ";
    printList(node1);
    //print copied list
    std::cout << "Copied list: ";
    printList(listCopy);
    
    return 0;
}