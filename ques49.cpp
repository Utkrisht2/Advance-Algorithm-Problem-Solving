/* How to find the intersection of two linked lists. Write its algorithm, program. Find its 
time and space complexities. Explain with suitable example.*/

#include <iostream>
using namespace std;

// Definition of singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    
    while (p1 != p2) {
        p1 = (p1 == nullptr) ? headB : p1->next;
        p2 = (p2 == nullptr) ? headA : p2->next;
    }
    
    return p1; // Could be null if no intersection
}

int main() {
    
    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);
    
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = common;
    
    ListNode* headB = new ListNode(3);
    headB->next = new ListNode(4);
    headB->next->next = common;
    
    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    
    return 0;
}
