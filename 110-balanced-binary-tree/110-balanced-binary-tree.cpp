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
     return (!root)?0:max(height(root->left),height(root->right))+1;        
    }
   
    
    bool check(TreeNode* root, bool &ans)
    {
        if(!root) return ans;
        
        if(root->left) check(root->left,ans);
        if(root->right) check(root->right, ans);
        
        if(abs(height(root->left)-height(root->right))>1) ans = false;
        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        return check(root,ans);
        
    }
};