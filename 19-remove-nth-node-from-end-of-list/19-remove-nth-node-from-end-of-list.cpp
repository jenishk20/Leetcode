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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int front=len-n-1;
        temp=head;
        if(len-n==0)
        {
            return head->next;
        }
        if(n==1)
        {
            
        }
        while(front--)
            temp=temp->next;
        // cout<<temp->val<<endl;
        // if(!temp->next)
        temp->next=temp->next->next;
        return head;
    }
};