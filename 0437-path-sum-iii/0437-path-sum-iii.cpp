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
    void solve(TreeNode* root, long long target)
    {
        if(root==nullptr) return;
        if(target==root->val)ans++;
        target-=root->val;
        solve(root->left,target);
        solve(root->right,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        solve(root,targetSum);
        
            pathSum(root->left,targetSum);
    
            pathSum(root->right,targetSum);
            
            return ans;
    }
};