#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create an instance of the Solution class
    Solution solution;

    std::cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}
