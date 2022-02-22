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
   void recur(TreeNode *root,int cmin,int cmax,int &ans)
    {
        if(!root)
            return;
        
        ans=max({ans,root->val-cmin,cmax-root->val});
        
        cmin=min({cmin,root->val});
        cmax=max({cmax,root->val});
       
        recur(root->left,cmin,cmax,ans);
        recur(root->right,cmin,cmax,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
       
        int ans=INT_MIN;
        recur(root,root->val,root->val,ans);
        return ans;
    }
};