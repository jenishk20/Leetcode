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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>ma;
        while(!q.empty())
        {
            auto curr=q.front();
            auto node =curr.first;
            auto x=curr.second.first;
            auto y=curr.second.second;
            
            ma[y][x].insert(node->val);
            q.pop();
            
            if(node->left)
            {
                q.push({node->left,{x+1,y-1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        for(auto i:ma)
        {
           
           cout<<i.first<<" ";
            vector<int>col;
            for(auto i:i.second)
            {
                col.insert(col.end(),i.second.begin(),i.second.end());
                cout<<i.first<<" ";
                for(auto it:i.second)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
            }
            ans.push_back(col);

        }
        return ans;
    }
};