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
    int ans=0;
   
    void recur(TreeNode *root,map<int,int>&ma)
    {
        if(!root)
            return;
        ma[root->val]++;
       
        if(!root->left and !root->right){
            
            int tt=0;
            for(auto i:ma)
            {
                if(i.second&1)
                    tt++;
            }
           
            if(tt<=1)
                ans++;
          
        }
        recur(root->left,ma);
        recur(root->right,ma);
        ma[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        string path="";
        map<int,int>ma;
        recur(root,ma);
        return ans;
    }
};