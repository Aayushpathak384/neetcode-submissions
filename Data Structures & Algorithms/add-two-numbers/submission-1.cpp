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
    ListNode* addTwoNumbers(ListNode* curr, ListNode* durr) {
        ListNode* dummy = new ListNode(0);
        ListNode* dap = dummy;
        int carry = 0;
        // add while both are not done
        while(curr!=nullptr || durr!=nullptr || carry!=0)
        {
            int sum = carry;
            if(curr)
            {
                sum += curr->val;
                curr = curr->next;
            }
            if(durr)
            {
                sum += durr->val;
                durr = durr->next;
            }
            ListNode*temp = new ListNode(sum%10);
            carry = (sum - sum%10)/10;
            dap->next = temp;
            dap = dap->next;
        }
        return dummy->next;
    }
};
