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
    ListNode* reverse(ListNode* head)
    {   
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* next = nullptr;
        ListNode*prev = nullptr;
        
        while(cur)
        {   
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;    
        }
        
        
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = reverse(head);
        
        int carry=0;
        
        ListNode* prev=nullptr;
        
        ListNode* ans = cur;
        
        
        while(cur)
        {
            int value = carry + cur->val*2;
            
            carry = value/10;
            
            value%=10;
            
            cur->val = value;
            
            
            prev = cur;
            cur = cur->next;
        }
        
    
        
        if(carry)
        {
            prev->next = new ListNode(carry);
            prev = prev->next;
        }
            
        
        
        return reverse(ans);
        
        
    }
};