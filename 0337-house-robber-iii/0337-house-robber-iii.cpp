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
    int rob(TreeNode* root) {
       if(root==nullptr) return 0;
       
        if(dp[root]) return dp[root];
        
        int ll=0,lr=0,l=0,rl=0,rr=0,r=0;
        if(root->left)
        {
             ll = rob(root->left->left);
             lr = rob(root->left->right);
             l = rob(root->left);
        }
        
        if(root->right)
        {
             rl = rob(root->right->left);
             rr = rob(root->right->right);
             r = rob(root->right);
        } 
        
        int ans1 = root->val + ll + lr + rl + rr;
        int ans2 = l+r;
        
        return dp[root]=max(ans1,ans2);
    }
};