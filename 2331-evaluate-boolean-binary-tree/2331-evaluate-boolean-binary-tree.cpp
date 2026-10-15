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
    bool evaluateTree(TreeNode* root) {

        if(!root->left && !root->right){
            if(root->val==1) return 1;
            else return 0;
        }
        
        int left = evaluateTree(root->left);
        int right = evaluateTree(root->right);

        if(root->val==3) return left && right;
        else return left || right;
    }
};