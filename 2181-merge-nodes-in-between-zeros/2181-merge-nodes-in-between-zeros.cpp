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
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    
    long long cnt=0;
    head= head->next;
    
        while(head!=nullptr)
        {
            long long v = head->val;
            if(v>0) cnt+=v;
            else
            {
                head->val = cnt;
                cnt=0;
                ans->next = head;
                ans = ans->next;
            }
            head=head->next;
        }
        return temp->next;
    }
};