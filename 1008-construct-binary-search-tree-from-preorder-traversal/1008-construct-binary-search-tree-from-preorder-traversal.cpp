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
    int i=0;
    TreeNode* solve(int bound,vector<int>& preorder)
    {
        if(i==preorder.size() || preorder[i]>bound) return nullptr;
        
        TreeNode * root = new TreeNode(preorder[i++]);
        
        root->left = solve(root->val,preorder);
        root->right = solve(bound,preorder);
         return root;        
    }

    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(INT_MAX,preorder);
    }
};