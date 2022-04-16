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
    void calc(TreeNode *root,int &num)
    {
        if(!root)
            return;
        calc(root->right,num);
        root->val=num+root->val;
        num=root->val;
        calc(root->left,num);
    }
    TreeNode* convertBST(TreeNode* root) {
        
        int ans=0;
        calc(root,ans);
        return root;
        
    }
};