#include <vector>
#include <iostream>


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
    bool isPalindrome(ListNode* head) {

        // create a vector to push values into
        std::vector<int> v;

        // loop through list to push values
        while(head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        // loop through vector to validate palindrome
        for(int i = 0; i < v.size() / 2; ++i) {
            if(v[i] != v[v.size() - i - 1]) return false;
        }
        return true;

    }
};

int main() {

    // create linked list: 1 -> 3 -> 4 -> 3 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    // class instance
    Solution Solution;

    // output
    std::cout << Solution.isPalindrome(head) << '\n';

    // free memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}