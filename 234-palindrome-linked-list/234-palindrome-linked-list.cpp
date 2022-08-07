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
    bool isPalindrome(ListNode* head) {
        
        vector<int> comp;
        
        ListNode* ptr = head;
        
        while(ptr)
        {
            comp.push_back(ptr->val);
            ptr= ptr->next;
        }
        
        reverse(comp.begin(),comp.end());
        
        int i = 0;
        while(head)
        {
         if(head->val != comp[i])
             return false;
            
            i++;
            head=head->next;
         
        }
        
        return true;
        
        
        
    }
};