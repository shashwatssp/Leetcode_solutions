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
    int ans=INT_MIN;
    
    int maxSum(TreeNode* root)
    {
        
        
        int left=0;
        int right=0;
        
        if(root->left)
            left = max(0, maxSum(root->left));
        
        if(root->right)
            right = max(0, maxSum(root->right));  
        
        ans = max(ans, left+right+ root->val);
        
        return max(left,right)+ root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};