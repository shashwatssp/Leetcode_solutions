/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool proceed(ListNode* head, TreeNode* root)
    {
        if(head==nullptr) return true;
        
        if(root==nullptr) return false;
        
        if(head->val == root->val)
        {
            return (proceed(head->next, root->left) || proceed(head->next, root->right));
        }
        
        return false;
        
    }
     bool search(ListNode* head, TreeNode* root)
    {
        if(head==nullptr || root==nullptr) return false;
        
        if(head->val == root->val)
        {
            bool x = proceed(head->next,root->left);
            bool y = proceed(head->next,root->right);
            
            if(x||y) return true;
        }
        
        return ( search(head,root->left) || search(head,root->right) );
         
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return search(head,root);
    }
};