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
