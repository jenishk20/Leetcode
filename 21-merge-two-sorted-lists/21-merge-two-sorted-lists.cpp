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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy=new ListNode(-1);
        
        // if(list1->val<list2->val)
        //     dummy->next=list1;
        // else
        //     dummy->next=list2;
        ListNode *temp=dummy;
        
        while(list1 and list2)
        {
            if(list1->val<list2->val)
            {
                temp->next=new ListNode(list1->val);
                temp=temp->next;
                list1=list1->next;
            }
            else
            {
                temp->next=new ListNode(list2->val);
                temp=temp->next;
                list2=list2->next;
            }
        }
        while(list1)
        {
            temp->next=new ListNode(list1->val);
                temp=temp->next;
                list1=list1->next;
        }
        while(list2)
        {
             temp->next=new ListNode(list2->val);
                temp=temp->next;
                list2=list2->next;
        }
        return dummy->next;
        
        
    }
};