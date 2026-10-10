/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node*& head,Node*& tail, int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        unordered_map<Node*,Node*>oldToNew;
        Node* ogNode=head;
        Node* cloneNode=cloneHead;
        while(ogNode!=NULL && cloneNode!=NULL){
            oldToNew[ogNode]=cloneNode;
            ogNode=ogNode->next;
            cloneNode=cloneNode->next;
        }
        ogNode=head;
        cloneNode=cloneHead;
        while(ogNode!=NULL){
            cloneNode->random=oldToNew[ogNode->random];
            ogNode=ogNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};