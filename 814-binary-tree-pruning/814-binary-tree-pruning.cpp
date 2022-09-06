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
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
        {
            if(root->val==1)
                return 1;
            else
                return 0;
        }
        int leftCount=recur(root->left);
        int rightCount=recur(root->right);
        
        if(leftCount==0)
            root->left=NULL;
        if(rightCount==0)
            root->right=NULL;
        
        return leftCount+rightCount+(root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        return (recur(root)==0)?NULL:root;
    }
};