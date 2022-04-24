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
    void recur(TreeNode *root,vector<int>&ans)
    {
        if(!root)
            return;
        recur(root->left,ans);
        ans.push_back(root->val);
        recur(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode *>se;
        while(1)
        {
            if(root!=NULL)
            {
                se.push(root);
                root=root->left;
            }
            else
            {
                if(se.empty())
                    break;
                root=se.top();
                ans.push_back(root->val);
                root=root->right;
                se.pop();
            }
        }
        // recur(root,ans);
        return ans;
    }
};