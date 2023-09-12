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
    TreeNode* solve(vector<int>& preorder, map<int,int> &index, int pre_start, int pre_end, int in_start, int in_end)
    {
        if(pre_start>pre_end || in_start> in_end) return nullptr;
        
        int ind = index[preorder[pre_start]];
        
        int lftsz = ind-in_start;
        
        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        root->left = solve(preorder,index, pre_start+1, pre_start+lftsz, in_start, ind-1 );
        root->right = solve(preorder,index, pre_start+ lftsz+1, pre_end, ind+1, in_end );   
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(preorder.size()!=n) return nullptr;
        
        map<int,int>index;
        
        for(int i=0;i<n;i++) index[inorder[i]]=i;
        
        return solve(preorder,index, 0, n-1, 0, n-1);
    }
};