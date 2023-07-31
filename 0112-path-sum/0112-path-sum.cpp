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
    map<TreeNode*,bool>dp;
    
    bool check(TreeNode* root, int sum)
    {
        if(root==nullptr) return dp[root]=false;
        
        if(dp[root]) return dp[root];
        
        if(root->left==nullptr && root->right==nullptr && sum==root->val) return dp[root]=true;
        return dp[root]= (check(root->left,sum-root->val)||check(root->right,sum-root->val));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       return check(root,targetSum);
    }
};