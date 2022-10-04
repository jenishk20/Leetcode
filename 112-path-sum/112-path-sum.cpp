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
    void recur(TreeNode *root,int targetSum,int &currSum,bool &ans)
    {
        if(!root)
            return;
        currSum+=root->val;
        
        if(!root->left and  !root->right)
        {
            cout<<currSum<<endl;
            if(currSum==targetSum)
                ans=true;
        }
        
        recur(root->left,targetSum,currSum,ans);
        recur(root->right,targetSum,currSum,ans);
        currSum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        int sum=0;
        recur(root,targetSum,sum,ans);
        return ans;
    }
};