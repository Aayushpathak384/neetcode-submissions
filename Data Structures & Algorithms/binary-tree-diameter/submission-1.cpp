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
    private: int call_dia(TreeNode* root)
    {
        if(root)
        {
            int left = call_dia(root->left);
            int right = call_dia(root->right);
            res = max(res , left + right );
            return max(left , right) + 1;
        }
        else 
        return 0;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int rest = call_dia(root);
        return res;
    }
};
