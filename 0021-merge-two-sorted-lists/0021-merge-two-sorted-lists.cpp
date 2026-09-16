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
    ListNode* solve(ListNode* first, ListNode* second){
        if(first->next==NULL){
            first->next=second;
            return first;
        }
        ListNode* curr1=first;
        ListNode* next1=first->next;
        ListNode* curr2=second;
        ListNode* next2=curr2->next;
        while(next1!=NULL && curr2!=NULL){
            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;
                curr1=curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;
                if(next1==NULL){
                    curr1->next=curr2;
                    return first;
                }
            }
        }
        return first;
    }
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first==NULL){
            return second;
        }   
        if(second==NULL){
            return first;
        }
        if(first->val<=second->val){
            return solve(first,second);
        }
        
            return solve(second,first);
        
    }
};