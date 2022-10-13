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
class BSTIterator
{
    public:
    stack<TreeNode *>st;
    bool reverse=true;
    BSTIterator(TreeNode *root,bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);     
    }
    void pushAll(TreeNode *root)
    {
        while(root)
        {
            st.push(root);
            if(reverse)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        auto top=st.top();
        st.pop();
        if(reverse)
            pushAll(top->left);
        else
            pushAll(top->right);
        
        return top->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
       
        while(i<j)
        {
             // cout<<i<<" "<<j<<endl;
            if(i+j==k) return true;
            if(i+j>k) j=r.next();
            else i=l.next();
        }
        return false;
    }
};