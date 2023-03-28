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
    map<TreeNode*,int>dp;
    int ans = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==nullptr) return 0;
        
        int left=0;
        int right=0;
        
        if(root->left)
            if(dp[root->left])
                left = dp[root->left];
        else left = max(0,solve(root->left));
        
        if(root->right)
            if(dp[root->right])
                right = dp[root->right];
        else right = max(0,solve(root->right));
        
        ans = max(ans, left+right+ root->val);
        dp[root]=ans;
        
        return max(left,right)+ root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};