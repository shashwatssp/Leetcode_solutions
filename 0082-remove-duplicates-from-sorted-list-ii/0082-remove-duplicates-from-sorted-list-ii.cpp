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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = new ListNode(0);
        cur->next = head;
        
        ListNode* ans = cur;
        
        while(head && head->next)
        {
            if(head->val != head->next->val)
            {
                cur->next =  head;
                cur = cur->next;
                head=head->next;
            }
            else
            {
                cur->next=nullptr;
                int x = head->val;
                while(head && head->val==x)
                {
                    head = head->next;
                }
            }
        }
        
        if(head) cur->next = head;
        
        return ans->next;
    }
};