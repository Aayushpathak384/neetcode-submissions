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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*> q;
        if(!root) return str;
        else
        {
            q.push(root);
            str +=root->val;
            str +="#";
            while(!q.empty())
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                {
                    q.push(curr->left);
                    str +=curr->left->val;
                    str +="#";
                }
                else 
                {
                    str +=" ";
                    str +="#";
                }

                if(curr->right)
                {
                    q.push(curr->right);
                    str +=curr->right->val;
                    str +="#";
                }
                else 
                {
                    str +=" ";
                    str +="#";
                }
            }
            return str;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        else
        {
            TreeNode* head = new TreeNode(data[0]);
            queue<TreeNode*>q;

            q.push(head);

            int n = data.length();
            int index = 0;

            while(!q.empty() && index<n)
            {
                TreeNode* curr= q.front();
                q.pop();
                
                index +=2;
                if(data[index] != ' ' && data[index]!='#')
                {   
                    curr->left = new TreeNode(data[index]);
                    q.push(curr->left);
                }
                
                index +=2;
                if(data[index] != ' ' && data[index]!='#')
                {   
                    curr->right = new TreeNode(data[index]);
                    q.push(curr->right);
                }
                
            }
            return head;
        }
    }
};
