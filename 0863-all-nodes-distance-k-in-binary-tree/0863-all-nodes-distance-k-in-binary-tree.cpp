/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* req;
    void setPar(map<TreeNode*,TreeNode*>&par, TreeNode* root, TreeNode* target)
    {
        if(root==nullptr) return;
        
        if(root==target)
            req = root;
        
        if (root->left)
        {
            par[root->left]=root;
            setPar(par,root->left,target);
        }
        if (root->right)
        {
            par[root->right]=root;
            setPar(par,root->right,target);
        }
        
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(k==0)
        {
            vector<int>ans;
            ans.push_back(target->val);
            return ans;
        }
        map<TreeNode*,TreeNode*>par;
        setPar(par,root,target);
        
        queue<TreeNode*>q;
        q.push(req);
        
        map<TreeNode*,bool>vis;
        
        while(q.size())
        {
            int sz = q.size();
            
            while(sz--)
            {
               TreeNode* node = q.front();
                q.pop();
                if(vis[node]) continue;
                
                vis[node] = true;
                
                if(par[node] && vis[par[node]]==false) q.push(par[node]);
                if(node->left && vis[node->left]==false) q.push(node->left);
                if(node->right && vis[node->right]==false) q.push(node->right);
            }
            k--;
            
            if(k==0)
                break;
        }
        
        vector<int>ans;
        
        while(q.size())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
        
    }
};