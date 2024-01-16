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
    int solve(TreeNode* root, map<int,int>&map)
    {
        if(root==nullptr)
            return 0;
        
        map[root->val]++;
        
        
        if(!root->left && !root->right)
        {
            int cnt=0;
            
            for(auto it: map)
                if(it.second&1) cnt++;
            
            if(cnt<=1)
            {
                map[root->val]--;
                return 1;
            }
        }
 
            
            int x = solve(root->left,map) + solve(root->right,map);
            
            map[root->val]--;
            
            return x;
            
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>map;
        return solve(root,map);
    }
};