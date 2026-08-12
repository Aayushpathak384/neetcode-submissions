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

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return nullptr;
        if(root == p || root== q) return root;
        TreeNode* lca = lowestCommonAncestor(root->left , p , q);
        TreeNode* lca2 = lowestCommonAncestor(root->right , p , q);
        
        if(lca && lca2 ) return root;
        else return lca? lca: lca2;
    }
};
