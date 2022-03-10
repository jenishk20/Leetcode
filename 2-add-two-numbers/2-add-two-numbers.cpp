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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum=0;
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(l1 or l2 or carry)
        {
            
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            cout<<sum<<" "<<carry<<endl;
            ListNode *newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            sum=0;
            
        }
        return dummy->next;
    }
};