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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        if(!root)
            return ans;
        stack<TreeNode *>se;
        se.push(root);
        while(!se.empty())
        {
            TreeNode *top=se.top();
            se.pop();
            ans.push_back(top->val);
             if(top->right)
                se.push(top->right);
            if(top->left)
                se.push(top->left);
           
        }
        return ans;
    }
};