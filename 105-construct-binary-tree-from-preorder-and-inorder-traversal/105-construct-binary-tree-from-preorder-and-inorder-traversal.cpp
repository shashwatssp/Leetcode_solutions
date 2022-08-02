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
    
    int pre = 0;
    TreeNode* ans(vector<int>& preorder, vector<int>&inorder, int s, int e)
    {
        if(s>e) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        
        int in;
        for(int i = s; i<=e; i++)
        {
            if(inorder[i]==root->val)
            {
            in = i;
                break;
            }

        }
        
     root->left = ans(preorder,inorder, s, in-1);
     root->right = ans(preorder, inorder, in+1, e);
        
        return root;
   
    }
    TreeNode* buildTree(vector<int>&preorder, vector<int>& inorder) {
        
        
         TreeNode* val = ans(preorder,inorder,0,inorder.size()-1);
        
         return val;
        
    }
};