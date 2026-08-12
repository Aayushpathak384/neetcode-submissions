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
    private: int m_level = 0;
    private: vector<int>arr;
    private: void printLevel(TreeNode* root , int level)
    {
        if(!root) return ;
        
        if(m_level< level)
        {
            arr.push_back(root->val);
            m_level = level;
        }
        printLevel(root->right , level + 1);
        printLevel(root->left , level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root== nullptr) return arr;

        printLevel(root , 1);

        return arr;
    }
};
