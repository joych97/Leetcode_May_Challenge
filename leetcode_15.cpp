/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
In this we are just interchanging the odd->next pointer with the even->next pointer and vice-versa. At the end we merge the odd pointer 
with the headEven pointer. We initialize 4 pointers at the beginning
headOdd=head 
headEven=head->next
odd=head;
even=head->next.

And we perform our operations on the odd and even pointers.
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    if(head!=NULL){
    ListNode* headOdd= head;
    ListNode* headEven= head->next;
    ListNode* odd= head;
    ListNode* even= head->next;
    while(odd->next != NULL && even!= NULL){
        odd->next=even->next;
        if(odd->next!=NULL){
            odd=odd->next;
        }
            even->next = odd->next;
            even=even->next ;  
        }
        odd->next=headEven;
        return headOdd;
    }
        return head;
    }
    
};