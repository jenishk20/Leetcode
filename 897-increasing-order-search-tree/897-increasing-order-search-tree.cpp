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
    void recur(TreeNode *root,vector<int>&inorder)
    {
        if(!root)
            return;
        recur(root->left,inorder);
        inorder.push_back(root->val);
        recur(root->right,inorder);
            
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>inorder;
        recur(root,inorder);
        
        TreeNode *nr=new TreeNode();
        TreeNode *tt=nr;
        for(auto i:inorder)
        {
            nr->right=new TreeNode(i);
            nr=nr->right;
        }
        return tt->right;
    }
};