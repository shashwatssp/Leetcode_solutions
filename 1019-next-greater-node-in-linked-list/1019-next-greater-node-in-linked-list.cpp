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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        map<int,vector<int>>map;
        stack<int>st;
        
        int i=0;
        
        while(head)
        {
            int x = head->val;
            
            while(st.size() && st.top()<x)
            {
                int ind = map[st.top()].back();
                map[st.top()].pop_back();
                
                ans[ind] = x;
                st.pop();
            }
            
            st.push(x);
            map[x].push_back(i++);
            ans.push_back(0);
            head=head->next;
        }
        
        return ans;
    }
};