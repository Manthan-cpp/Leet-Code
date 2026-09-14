/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        map<ListNode*,bool> vis;
        ListNode* temp=head;
        while(temp!=NULL){
            if(vis[temp]==true){
                return true;
            }
            vis[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};