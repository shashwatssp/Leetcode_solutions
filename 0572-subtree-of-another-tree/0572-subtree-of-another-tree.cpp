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
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr && subRoot==nullptr) return true;
         if(root==nullptr || subRoot==nullptr) return false;
        
        return (root->val==subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right));
    }
    
    bool search(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr && subRoot == nullptr) return true;
        if(root==nullptr || subRoot == nullptr) return false;
        
        return (isSame(root,subRoot) || search(root->left,subRoot) || search(root->right, subRoot));
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search (root, subRoot);
        
        
    }
};