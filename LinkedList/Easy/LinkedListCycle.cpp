#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // there is only one node or no node return false
        if(head == nullptr || head->next == nullptr) return false;

        // make two pointers pointing at the head of the list
        ListNode *slow = head;
        ListNode *fast = head;

        // loop through the list to see if there is a cycle if there is return true
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }
        // if there is no cycle then return false
        return false;
    }
};
 int main() {

    // make a list 1 -> 3 -> -1 -> 4 -> 5: with 5 pointing to 3
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(-1);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);

    head->next = node1; 
    node1->next = node2; 
    node2->next = node3; 
    node3->next = node4; 
    node4->next = node2;

    // Create instance class of solution
    Solution Solution;

    //print solution
    std::cout << Solution.hasCycle(head) << '\n'; 


    return 0;
 }