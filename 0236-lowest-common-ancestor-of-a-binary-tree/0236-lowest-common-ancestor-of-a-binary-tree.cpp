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
   map<TreeNode*,TreeNode*> par;
    void parent(TreeNode* root, TreeNode* pare)
    {
    if(root== nullptr) return;
        
    if(pare)    
    par[root] = pare;
        
        parent(root->left,root);
        parent(root->right,root);
        
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     parent(root, nullptr);
        

     
     map<TreeNode*,TreeNode*> p_par;
        
        while(par[p])
        {   
            TreeNode* x = par[p];
            p_par[p] = p;
            p = x;
            
        }

        
        while(par[q])
        {   
            if(p_par[q])
                return q;
            
            q = par[q];
            
                if(p_par[q])
                return q;
        }
        return root;
    }
};