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
    private: bool check = true;
    private: int height(TreeNode* root)
    {
        if(root)
        {
            int l = height(root->left);
            int r = height(root->right);
            int res = abs(l - r);
            if(res!=0 && res!=1)
            check = false;
            return max(l , r) + 1;
        }
        else return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root)
        {
            int l = height(root->left);
            int r = height(root->right);
            int res = abs(l - r);
            if(check == false) return false;
            if(res == 0 || res == 1)
            return true;
            else return false;
        }
        return true;
    }
};
