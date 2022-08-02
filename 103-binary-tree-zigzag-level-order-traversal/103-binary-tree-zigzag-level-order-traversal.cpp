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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        q.push(root);
        
        int ind = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int> level;
            
            while(n--)
            {
            TreeNode* top = q.front();
            q.pop();
            level.push_back(top->val);
                
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            }
            
            if(ind&1) reverse(level.begin(),level.end());
            
            ans.push_back(level);
            
            ind++;

        }
        
        return ans;
        
    }
};