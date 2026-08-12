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

    private: bool flag = false;

    private: void match(vector<TreeNode*>arr , vector<TreeNode*> brr)
    {
        if(arr.size() != brr.size()) return ;

        for(int i = 0 ; i< arr.size() ; i++)
        {
            if(arr[i] == nullptr && brr[i]!=nullptr) return ;
            else if(arr[i]!= nullptr && brr[i]==nullptr) return ;
            else if(arr[i] && brr[i])
            {
                if(arr[i]->val != brr[i]->val) return ;
                else continue;
            }
            else continue;
        }
        flag = true;
        return ;
    }

    private: vector<TreeNode*> fill_arr(vector<TreeNode*>arr , TreeNode* root)
    {
        
        queue<TreeNode*>q;
        TreeNode*curr = root;

        q.push(curr);
        arr.push_back(q.front());

        while(!q.empty())
        {
            if(q.front()->left)
            {
                q.push(q.front()->left);
                arr.push_back(q.front()->left);
            }
            else arr.push_back(nullptr);

            if(q.front()->right)
            {
                q.push(q.front()->right);
                arr.push_back(q.front()->right);
            }
            else arr.push_back(nullptr);

            q.pop();
        }
        
        return arr;
    }

    private: void find_subroot(vector<TreeNode*> arr ,TreeNode* root)
    {
        if(flag) return ;
        if(root)
        {
            find_subroot(arr , root->left );

            vector<TreeNode*>brr;
            brr = fill_arr(brr , root);

            match(arr , brr);
            if(flag) return ;

            find_subroot(arr , root->right);
        }
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        vector<TreeNode*>arr;

        if(!root && !subRoot) return true;
        if(root && !subRoot)  return false;
        if(!root && subRoot)  return false;

        arr = fill_arr(arr , subRoot);

        find_subroot(arr , root);

        return flag;
        
    }
};
