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
    ListNode* merge(ListNode* node , ListNode* resultant)
    {
        if(resultant== nullptr) return node;
        if(node == nullptr) return resultant;

        if(node->val< resultant->val)
        {
            ListNode*temp = node->next;
            node->next = resultant;
            resultant = node;
            node = temp;
            
        }

        ListNode*curr = resultant;
        ListNode*up = node;
        ListNode* prev = curr;

        while(curr && node)
        {
           
            if(curr->val <= node->val)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                up = node->next;

                prev->next = node;
                node->next = curr;
                prev = node;

                node = up;
            }
        }
        while(node)
        {
            prev->next = node;
            prev = node;
            node = node->next;
        }

        return resultant;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        ListNode*resultant = nullptr;

        for(int i = 0 ; i< n;  i++)
        {
            ListNode*node = lists[i];
            resultant = merge(node , resultant);
        }

        return resultant;
    }
};
