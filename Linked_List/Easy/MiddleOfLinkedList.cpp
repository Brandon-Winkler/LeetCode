#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) return head;              // if there is only one value in the list return the list

        ListNode* slow = head;                              // set a slow pointer to beginning of list to return when we reach the middle
        ListNode* fast = head;                              // set a fast pointer to beginning of list to track when we have reached the end
        while(fast != nullptr && fast->next != nullptr){    // loop through list while fast and the node after fast aren't null
            slow = slow->next;                              // increment slow by 1
            fast = fast->next->next;                        // increment fast by 2
        }
        return slow;                                        // return the middle
    }
};

// Function to print the linked list
void printList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        cout<<current->val<<" -> ";
        current = current->next;
    }
    cout<<endl;
}

// driver program
int main(){
    // initialize lists
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    // solution class instance
    Solution Solution;

    ListNode* s1 = Solution.middleNode(head);
    ListNode* s2 = Solution.middleNode(head2);

    // outputs
    cout<<"Second half of first list: ";
    printList(s1);

    cout<<"Second half of second list: ";
    printList(s2);
    
    return 0;
}