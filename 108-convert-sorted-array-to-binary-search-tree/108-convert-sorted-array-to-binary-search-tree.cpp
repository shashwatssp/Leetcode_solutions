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
    TreeNode* BST(int lo, int hi, vector<int>&nums)
    {
        if(lo==hi) return (new TreeNode(nums[lo]));
        if(lo>hi) return NULL;
        
        int mid = (lo+hi)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = BST(lo,mid-1,nums);
        temp->right = BST(mid+1,hi,nums);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int lo=0;
        int hi = nums.size()-1;
        return BST(lo,hi,nums);
    }
};