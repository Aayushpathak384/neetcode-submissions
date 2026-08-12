/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private: vector<TreeNode*> fill_tree_data(vector<TreeNode*> arr  , TreeNode* p)
    {
        queue<TreeNode*>q;
        TreeNode* curr = p;
        q.push(curr);
        arr.push_back(q.front());
        while(q.empty()== false)
        {
            if(q.front()->left)
            {
                q.push(q.front()->left);
                arr.push_back(q.front()->left);
            }
            else 
            arr.push_back(nullptr);

            if(q.front()->right)
            {
                q.push(q.front()->right);
                arr.push_back(q.front()->right);
            }
            else
            arr.push_back(nullptr);

            q.pop();
            
        }
        return arr;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==nullptr && q== nullptr) return true;

        vector<TreeNode*> arr , brr;
        // put value in first q_p
        
        if(p)
        arr = fill_tree_data(arr , p);

        if(q)
        brr = fill_tree_data(brr , q);

        if(arr.size()!= brr.size()) return false;

        for(int i = 0 ; i< arr.size() ; i++)
        {
            if(arr[i] == nullptr && brr[i]!=nullptr) return false;
            else if(arr[i]!= nullptr && brr[i]==nullptr) return false;
            else if(arr[i] && brr[i])
            {
                if(arr[i]->val != brr[i]->val) return false;
                else continue;
            }
            else continue;
        }
        return true;
    }
};
