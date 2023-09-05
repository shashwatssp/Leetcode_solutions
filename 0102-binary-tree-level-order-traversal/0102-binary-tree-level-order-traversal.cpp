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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    q.push(root);

    while(q.size())
    {
        int sz = q.size();
        vector<int>temp;
        
        while(sz--)
        {
         TreeNode* top = q.front();
         q.pop();
            
            if(top && top->left) q.push(top->left);
            if(top && top->right) q.push(top->right);
            
            
            if(top)
            temp.push_back(top->val);
        }
        if(temp.size())
        ans.push_back(temp);
    }
        
        return ans;
        
    }
};