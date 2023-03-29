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
    int ans=0;
    int has_camera = 0;
    int needs_camera = -1;
    int covered = 1;
    
    map<TreeNode*,int>dp;
    
    int solve(TreeNode* root)
    {
        if(root==nullptr)
            return covered;
        
        if(dp[root]) return dp[root];
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left==needs_camera || right == needs_camera)
        {
            ans++;
            return dp[root] =  has_camera;
        }
        else if (left == has_camera || right == has_camera)
        {
            return dp[root]=covered;
        }
        else
        {
            return dp[root] = needs_camera;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root)==needs_camera) ans++;
        return ans;
    }
};