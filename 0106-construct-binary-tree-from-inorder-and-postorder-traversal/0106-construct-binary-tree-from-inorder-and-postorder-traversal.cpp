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
    map<int,int>map;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe)
    {
        if(is>ie || ps>pe) return nullptr;
        
        TreeNode* head = new TreeNode(postorder[pe]);
        int ind = map[postorder[pe]];
        
        head->left = build(inorder,postorder,is,ind-1,ps, ps+ ind-is-1);
        head->right = build(inorder,postorder,ind+1,ie, ps+ ind-is, pe-1);
        
        return head;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return nullptr;
        
        int n = inorder.size();
        for(int i=0;i<n;i++)
            map[inorder[i]]=i;
        
        return build(inorder,postorder,0,n-1,0,n-1);
    }
};