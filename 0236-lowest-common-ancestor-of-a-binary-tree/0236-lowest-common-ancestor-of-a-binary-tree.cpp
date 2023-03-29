/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
    if(root==NULL)
        return false;
     
        if(ans) return true;
        
    bool self = (root->val == p->val || root->val == q->val);
    bool right = solve(root->right,p,q);
    if(ans) return true;
    bool left = solve(root->left,p,q);
    if(ans) return true;
    
    if(self+right+left==2) ans = root;    
    
    return self || right || left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};