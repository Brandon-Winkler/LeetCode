#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(second){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Merge the two halves
        ListNode* first = head;
        second = prev;

        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};

// driver program
int main(){
    // first list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    // second list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout<<"Lists before reordering: "<<"\n\n";
    printList(head1);
    cout<<'\n';
    printList(head2);
    cout<<'\n';

    // class instance
    Solution Solution;

    // reorder lists
    Solution.reorderList(head1);
    Solution.reorderList(head2);

    cout<<"Lists after reordering: "<<"\n\n";
    printList(head1);
    cout<<'\n';
    printList(head2);
    cout<<'\n';

    return 0;
}
