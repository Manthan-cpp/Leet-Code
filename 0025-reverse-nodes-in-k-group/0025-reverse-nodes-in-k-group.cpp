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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp = head;
        int c = 0;
        while (temp != NULL && c < k) {
            temp = temp->next;
            c++;
        }
        if (c < k) {
            return head;
        }
        ListNode* forward=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        c=0;
        while(curr!=NULL && c<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            c++;
        }
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }
        return prev;
    }
};