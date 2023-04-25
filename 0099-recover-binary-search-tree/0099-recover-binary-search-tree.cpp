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
    
    TreeNode* Right(TreeNode* left, TreeNode* cur)
    {
        while(left->right!=nullptr &&           left->right!=cur)
            left = left->right;
        
        return left;
    }
    void recoverTree(TreeNode* root) {
       TreeNode* cur = root;
        TreeNode* a = nullptr;
        TreeNode* b = nullptr;
        TreeNode* prev = nullptr;
        
        while(cur!=nullptr)
        {
            TreeNode* lft = cur->left;
            
            if(lft==nullptr)
            {
                if(prev!=nullptr && prev->val>cur->val)
                {
                    if(a==nullptr)
                        a = prev;
                        b= cur;
                }
                prev=cur;
                cur=cur->right;
            }
            else
            {
             TreeNode* rmn = Right(lft,cur);
             
                if(rmn->right==nullptr)
                {
                    rmn->right=cur;
                    cur = cur->left;
                }
                else 
                {
                  rmn->right = nullptr;  
                if(prev->val>cur->val)
                {
                    if(a==nullptr)
                        a = prev;
                    b= cur;
                }
                prev=cur;
                cur=cur->right;                    

                }
  
            }
        }
        
        swap(a->val,b->val);
    }
};