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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
            
        }
        
        int i=0;
        ListNode *start,*end;
        int p=k;
        temp=head;
        p--;
        while(p--)
            temp=temp->next;
        start=temp;
        
        int l=len-k;
        temp=head;
        while(l--)
        {
            temp=temp->next;
        }
        k=start->val;
         l=temp->val;
        
        start->val=l;
        temp->val=k;
        // cout<<start->val<<" "<<temp->val;
        // swap(start,temp);
        return head;
    }
};