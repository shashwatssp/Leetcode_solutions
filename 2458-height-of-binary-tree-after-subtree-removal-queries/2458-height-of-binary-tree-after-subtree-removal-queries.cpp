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
    int arr[1000050],map[1000050],mapend[1000050];
    void dfs(TreeNode* root, int level, int &idx)
    {
        if(root==nullptr) return;
        
        arr[idx] = level;
        map[root->val] = idx;
        idx++;
        dfs(root->left,level+1, idx);
        idx++;
        dfs(root->right,level+1, idx);
        
        mapend[root->val] = idx;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int idx=1;
        dfs(root,0,idx);
        
        vector<int>pre(1000050,0),suff(1000050,0);
        
        for(int i=1;i<1000050;i++)
        pre[i] = max(arr[i],pre[i-1]);
        
        for(int i=1000030;i>=0;i--)
        suff[i] = max(arr[i],suff[i+1]);
        
        vector<int>ans;
        
        for(auto it : queries)
        {   
            int idx = map[it];
            int idxend = mapend[it];
            
            ans.push_back(max(pre[idx-1],suff[idxend]));
        }
        
        
        
        return ans;
    }
};