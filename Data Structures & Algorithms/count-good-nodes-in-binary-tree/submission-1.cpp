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
    private: int res = 0;
    private: void cal(TreeNode* root , int highest_val)
    {
        if(root)
        {
            if(root->val >= highest_val) res++;
            
            highest_val = max(highest_val , root->val);

            if(root->left) cal(root->left , highest_val);
            
            if(root->right) cal(root->right , highest_val);
        }
    }
public:
    int goodNodes(TreeNode* root) {

        if(!root) return 0;
        
        cal(root , INT_MIN);

        return res;
    }
};
