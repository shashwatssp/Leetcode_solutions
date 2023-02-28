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
    ListNode* mergeNodes(ListNode* head) {
    
        long long temp=0;
        ListNode* ans = head;
        ListNode* r=ans;
        head=head->next;
        while(head!=nullptr)
        {
            long long v= head->val;
            
            if(v>0) temp+=v;
            else
            {
              head->val= temp; 
              temp=0;
              ans->next = head;
              ans = ans->next;
              
            }
            head = head->next;
        }
        return r->next;
    }
};