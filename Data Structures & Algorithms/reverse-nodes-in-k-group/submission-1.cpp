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
    pair<ListNode* , ListNode*> reverse(ListNode* node)
    {
        ListNode* curr = node;
        ListNode* prev = nullptr;

        while(curr)
        {
            ListNode*up = curr->next;
            curr->next = prev;
            prev = curr;
            curr = up;
        }

        return {prev , node};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*node = head;
        ListNode*prev = nullptr;

        while(node)
        {
            ListNode* curr = node;
            ListNode*store = nullptr;

            for(int i = 0 ; i< k - 1 && curr; i++)
            curr = curr->next;

            if(curr)
            {
                store = curr->next;
                curr->next = nullptr;
                pair<ListNode* , ListNode*> res = reverse(node);

                if(prev)
                {
                    prev->next = res.first;
                }
                else
                head = res.first;
                prev = res.second;
                node = store;
            }
            else
            {
                if(prev)
                prev->next = node;
                break;
            }

        }
        return head;
    }
};
