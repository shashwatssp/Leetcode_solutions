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
    map<int,int>leftChild,rightChild,parent;
    
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
            parent[it[1]]= it[0];
            
            if(it[2]==1)
                leftChild[it[0]]=it[1];
            else
                rightChild[it[0]]=it[1];
        }
        
        int x = descriptions[0][0];
        
        while(parent[x])
            x = parent[x];
        
        
        return solve(x);
    }
};