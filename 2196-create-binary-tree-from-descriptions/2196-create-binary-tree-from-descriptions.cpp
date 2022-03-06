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
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *>ma;
        unordered_map<int,int>indegree;
        
        for(auto &i:descriptions)
        {
            int parent=i[0];
            int child=i[1];
            indegree[child]++;
            if(ma.count(parent)==0)
                ma[parent]=new TreeNode(parent);
            if(ma.count(child)==0)
                ma[child]=new TreeNode(child);
            
            if(i[2]==1)
            {
                ma[parent]->left=ma[child];
            }
            else
            {
                ma[parent]->right=ma[child];
            }
        }
        
        for(auto i:ma)
        {
            if(indegree[i.first]==0)
                return i.second;
        }
        return NULL;
        
    }
};