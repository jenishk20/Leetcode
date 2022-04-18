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
    void recur(TreeNode *root,TreeNode *&dummy)
    {
        if(!root)
            return;
        recur(root->left,dummy);
        dummy->right=new TreeNode(root->val);
        dummy=dummy->right;
        recur(root->right,dummy);
            
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy=new TreeNode(-1);
        TreeNode *tt=dummy;
        recur(root,dummy);
        
        return tt->right;
    }
};