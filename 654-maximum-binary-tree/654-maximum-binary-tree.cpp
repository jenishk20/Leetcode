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
    int findMaxElementIdx(vector<int>&nums,int low,int high)
    {
        int n=nums.size();
        int mx=-1e6;
        int idx=0;
        for(int i=low;i<=high;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode *recur(vector<int>&nums,int low,int high)
    {
        if(low>high) return NULL;
        
        int idx=findMaxElementIdx(nums,low,high);
        TreeNode *newNode=new TreeNode(nums[idx]);
        newNode->left=recur(nums,low,idx-1);
        newNode->right=recur(nums,idx+1,high);
        
        return newNode;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n=nums.size()-1;
        return recur(nums,0,n);    
      
            
    }
};