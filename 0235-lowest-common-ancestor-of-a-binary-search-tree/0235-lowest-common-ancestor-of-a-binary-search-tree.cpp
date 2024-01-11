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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mn = min(p->val,q->val);
        int mx = max(p->val,q->val);
        
        while(root)
        {
            if(root->val>=mn and root->val<=mx)
            return root;
            else
            {
                if(root->val>mx)
                    root = root->left;
                else
                    root = root->right;
            }

        }
        
        return root;
        
    }
};