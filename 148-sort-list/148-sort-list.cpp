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
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        vector<int> sorted;
        
        ListNode* ptr = head;
        
        while(ptr) sorted.push_back(ptr->val), ptr = ptr->next;
        
        sort(sorted.begin(),sorted.end());
        
        ListNode* ptr2 = head;
        
        int i=0;
        
        while(ptr2) 
        {
            ptr2->val = sorted[i++];
            ptr2=ptr2->next;
        }
        
        return head;
        
    }
};