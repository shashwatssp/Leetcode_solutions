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
    bool isSymmetric(TreeNode* root) {
       if(root==nullptr) return true;
        
        queue<TreeNode*>q1,q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(q1.size() && q2.size())
        {
            if(q1.size()!=q2.size()) return false;
            int sz = q1.size();
            while(sz--)
            {
               TreeNode* x1 = q1.front();
                q1.pop();
                TreeNode* x2 = q2.front();
                q2.pop();
                
                if(x1==nullptr && x2==nullptr) continue;
                if(x1==nullptr || x2==nullptr) return false;
                
                if(x1->val != x2->val) return false;
                
                q1.push(x1->left);
                q1.push(x1->right);
                
                q2.push(x2->right);
                q2.push(x2->left);  
            }
        }
        return true; 
    }
};