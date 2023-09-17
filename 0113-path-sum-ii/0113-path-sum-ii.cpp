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
    vector<vector<int>>ans;
    void solve(TreeNode* root, int target, vector<int>temp)
    {
        if(root==nullptr) return;
        
        if(root->left== nullptr && root->right==nullptr && root->val==target)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(root->val);
        solve(root->left, target- root->val, temp);
        solve(root->right, target- root->val, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
       solve(root,targetSum,temp);
        return ans;
    }
};