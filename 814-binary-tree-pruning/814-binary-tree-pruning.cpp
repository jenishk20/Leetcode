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
    int recur(TreeNode *root)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right)
        {
            if(root->val==1)
                return 1;
            return 0;
        }
        int left=recur(root->left);
        int right=recur(root->right);
        
        if(left==0)
            root->left=NULL;
        if(right==0)
            root->right=NULL;
        
        return left+right+(root->val==1);
        
       
        

           
    }
    bool contains(TreeNode *root)
    {
        if(!root)
            return false;
        if(root->val==1)
            return true;
        return contains(root->left) or contains(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        return (recur(root))==0?NULL:root;
        // return root;
    }
};