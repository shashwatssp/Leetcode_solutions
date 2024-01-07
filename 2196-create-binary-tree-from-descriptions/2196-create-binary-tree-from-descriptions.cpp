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
    map<int,int>leftChild,rightChild,par;
    
    TreeNode* solve(int val)
    {
       if(val==0) return nullptr;
        
       TreeNode* root = new TreeNode(val);
        
        root->left = solve(leftChild[val]);
        root->right = solve(rightChild[val]);
        
        return root;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        
        for(auto it : descriptions)
        {
            if(it[2]==1)
                leftChild[it[0]]=it[1];
             if(it[2]==0)
                 rightChild[it[0]]=it[1];
             
            par[it[1]] = it[0];
        }
        
        int x = descriptions[0][0];
        
        while(par[x])
        {
            x = par[x];
        }
        
        TreeNode* root = new TreeNode(x);
        
        return solve(x);
    }
};