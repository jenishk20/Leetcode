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
    void recur(TreeNode *root,int  maxSeenTillNow,int &count)
    {
        if(!root)
            return;
        
        if(root->val>= maxSeenTillNow)
        {
            maxSeenTillNow=root->val;
            count++;
        }
        recur(root->left,maxSeenTillNow,count);
        recur(root->right,maxSeenTillNow,count);
    }
    int goodNodes(TreeNode* root) {
        
        int count=0;
        recur(root,INT_MIN,count);
        
        return count;
    }
};