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
    private: int count = 0;
    private: void call(TreeNode* root , int k )
    {
        if(root)
        {
            call(root->left , k); 

            count++;
            if(count == k)
            {
                res = root->val;
                return;
            }
            call(root->right , k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
         call(root , k);
         return res;
    }
};
