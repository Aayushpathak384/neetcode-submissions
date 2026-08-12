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
    private: int res = INT_MIN;
    private: int maxPathSu(TreeNode* root)
    {
        if(!root)return 0;
        else
        {
            int l = maxPathSu(root->left);
            if(l< 0) l = 0;

            int r = maxPathSu(root->right);
            if(r< 0) r = 0;

            res = max(res , l +r + root->val);

            l = (l >= r)? l:r;
            int sum = l + root->val;
            
            if(sum < 0 ) sum = 0;
            return sum;
        }
    }
public:
    int maxPathSum(TreeNode* root) {
       int temp =  maxPathSu(root);
       return res;
    }
};
