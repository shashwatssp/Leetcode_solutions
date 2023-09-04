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
    bool ans = true;
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
              TreeNode* cur = q.front();
              
              q.pop();
                
                if(ans==false)
                {
                    if(cur->left || cur->right) return false;
                }
                
              if(cur->left) q.push(cur->left);
                else {
                    if(ans=true) ans = false;
                }
              if(cur->right) q.push(cur->right); 
                                else {
                    if(ans=true) ans = false;
                }
                
              if(cur->right && (cur->left==nullptr)) return false;
            }
        }
        return true;
    }
};