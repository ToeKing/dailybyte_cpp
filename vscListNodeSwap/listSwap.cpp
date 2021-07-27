#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* Given a linked list, swap every two adjacent nodes and return its head.
   You must solve the problem without modifying the values in the list's
   nodes (i.e., only nodes themselves may be changed.) */

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
void swapPair(ListNode* head) {
    if(head && head->next) {
        //swap(head->val, head->next->val);
        ListNode* tmp = head;
        head = head->next;
        head->next = tmp;
        swapPair(head->next->next);
    }
}

int main()
{
    ListNode a = ListNode(4);
    ListNode z = ListNode(3, &a);
    ListNode y = ListNode(2, &z);
    ListNode x = ListNode(1, &y);
    
    ListNode* lPtr = &x;
    while(lPtr) {
        cout << lPtr->val << " ";
        lPtr = lPtr->next;
    }
    cout << endl;

    swapPair(&x);
    lPtr = &x;
    cout << "After swap:" << endl;
    while(lPtr) {
        cout << lPtr->val << " ";
        lPtr = lPtr->next;
    }
    cout << endl;
}