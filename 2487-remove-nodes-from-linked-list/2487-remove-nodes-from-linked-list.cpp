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
    ListNode* removeNodes(ListNode* head) {
        
        if(head==nullptr) return head;
        vector<int>v;
        ListNode* cur = head;
        
        while(cur!= nullptr)
        {
            v.push_back(cur->val);
            cur = cur->next;            
        }
        
        int n = v.size();
        
        for(int i=n-2;i>=0;i--)
            v[i] = max(v[i],v[i+1]);
        
        
        ListNode dummy(0);
        ListNode* start = &dummy;
        ListNode*ans = start;
        
        cur = head;
        
        int i=0;
        
        while(cur!=nullptr)
        {
            if(cur->val==v[i])
            {
                start->next = new ListNode(v[i]);
                start = start->next;
            }
            cur = cur->next;
            
            i++;
                
        }
        
        return ans->next;
    }
};