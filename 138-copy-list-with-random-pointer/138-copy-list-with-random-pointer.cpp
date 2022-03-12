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
    Node* copyRandomList(Node* head) {
        map<Node *,Node *>ma;
        Node *temp=head;
        while(temp)
        {
            ma[temp]= new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            ma[temp]->next=ma[temp->next];
            ma[temp]->random=ma[temp->random];
            temp=temp->next;
        }
        return ma[head];
        
        
    }
};