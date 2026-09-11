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
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int ans=getLength(head)/2;
        int c=0;
        ListNode* temp=head;
        while(c<ans){
            temp=temp->next;
            c++;
        }
        return temp;
    }
};