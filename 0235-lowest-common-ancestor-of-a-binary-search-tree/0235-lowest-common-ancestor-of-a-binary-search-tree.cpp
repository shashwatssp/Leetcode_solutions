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
    TreeNode* ans;
    int mn;
    int mx;
    void solve(TreeNode* root)
    {
        if(root==nullptr) return;
        
        if(root->val>=mn && root->val<=mx)
        {
            ans = root;
            return;
        }
            
        
        solve(root->left);
        solve(root->right);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mn = min(p->val,q->val);
        mx = max(p->val,q->val);
        
        solve(root);
        return ans;
    }
};