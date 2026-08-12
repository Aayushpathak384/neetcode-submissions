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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr)
        return head;
        else{
            ListNode* curr = head;
            ListNode* up = curr->next;
            ListNode* prev = nullptr;
            while(up!=nullptr)
            {
                up = curr->next;
                curr->next = prev;
                prev = curr;
                curr = up;
            }
            return prev;
        }
    }
};
