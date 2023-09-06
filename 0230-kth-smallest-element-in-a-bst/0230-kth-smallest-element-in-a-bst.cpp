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
    int val;
    int ans=0;
    int solve(TreeNode* root)
    {   
        
        if(root->left) solve(root->left);
        val--;
        if(val==0)
        {   
            ans = (root->val);
        }
        if(root->right) solve(root->right);
        
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        val=k;
        return solve(root);
    }
};