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
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    int ans(TreeNode* root , int &mx)
    {
       if(!root) return mx;
       if(root->left) ans(root->left,mx);
       mx = max(mx,(height(root->left) + height(root->right)));
       if(root->right) ans(root->right,mx);
       return mx;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        return ans(root,mx);
    }
};