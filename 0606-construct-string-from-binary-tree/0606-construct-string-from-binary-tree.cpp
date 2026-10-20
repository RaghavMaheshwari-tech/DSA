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
    string solve(TreeNode* root){
        if(!root->left && !root->right){
            return to_string(root->val);
        }
        

        string temp;
        temp = to_string(root->val);

        string left = (root->left)? '(' + solve(root->left) + ')' : "()";
        if(root->right){
            return temp + left + '(' + solve(root->right) + ')';
        }
        else return temp + left;

    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};