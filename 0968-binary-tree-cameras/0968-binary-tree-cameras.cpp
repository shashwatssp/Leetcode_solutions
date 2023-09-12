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
    map<TreeNode*,int>dp;
    int solve (TreeNode* root)
    {
        if(root==nullptr) return dp[root]=15;
        
        if(dp[root]) return dp[root];
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left==5 || right==5)
        {
            ans++;
            return dp[root] = 10;
        }
        else if(left==10 || right==10)
            return dp[root]=15;

        else 
            return dp[root] = 5;
    }
    int minCameraCover(TreeNode* root) {
        solve(root);
        if(dp[root]==5) ans++;
        return ans;
    }
};