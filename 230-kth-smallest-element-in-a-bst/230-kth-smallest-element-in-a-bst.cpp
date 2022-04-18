/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recur(TreeNode *root,int k,priority_queue<int>&pq)
    {
        
        if(!root)
            return;
        
        //cout<<root->val<<endl;
       
        pq.push(root->val);
         if(pq.size()>k)
            pq.pop();
        recur(root->left,k,pq);
        recur(root->right,k,pq);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        
        recur(root,k,pq);
        return pq.top();
        
    }
};