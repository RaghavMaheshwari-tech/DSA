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
    string tree2str(TreeNode* root) {
        if(!root->left && !root->right) return to_string(root->val);
        
        string temp;
        temp = to_string(root->val) + ((root->left)? '(' + tree2str(root->left) + ')' : "()");

        if(root->right){
            return temp + '(' + tree2str(root->right) + ')';
        }
        else return temp;
    }
};