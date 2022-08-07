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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(n==1 && head->next==NULL) return NULL;
        
        ListNode* ptr = head;
        ListNode* help = head;
        
        while(n--) ptr = ptr->next;
        
        if(!ptr) return head->next;
            
        while(ptr->next)
        {
        ptr = ptr->next;
        help = help->next;
        }
        
        help->next = help->next->next;
        
        return head;
        
    }
};