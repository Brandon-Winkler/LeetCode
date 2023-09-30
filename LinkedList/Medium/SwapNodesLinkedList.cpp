#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int length = getLength(head);
        if (k <= 0 || k > length)
            return head; // Invalid k value

        ListNode *kthNodeFromStart = head;
        ListNode *kthNodeFromEnd = head;
        ListNode *temp = head;

        // Move kthNodeFromStart to the kth node from the beginning
        for (int i = 1; i < k; ++i)
            kthNodeFromStart = kthNodeFromStart->next;

        // Move kthNodeFromEnd to the kth node from the end
        for (int i = 0; i < length - k; ++i)
            kthNodeFromEnd = kthNodeFromEnd->next;

        // Swap the values of the two nodes
        int tempVal = kthNodeFromStart->val;
        kthNodeFromStart->val = kthNodeFromEnd->val;
        kthNodeFromEnd->val = tempVal;

        return head;
    }
private:
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head != nullptr)
        {
            head = head->next;
            length++;
        }
        return length;
    }
};

void printList(ListNode *head)
    {
        while (head != nullptr)
        {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Swapping the 2nd node from the beginning and end
    std::cout << "Original List: ";
    printList(head);

    Solution Solution;
    ListNode* newHead = Solution.swapNodes(head, k);

    std::cout << "List after swapping nodes: ";
    printList(newHead);

    // Clean up the memory (not necessary for the algorithm)
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
