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
    typedef long long ll;
    bool solve(TreeNode* root, ll lower, ll upper){
        if(!root) return 1;
        if(root->val<=lower || root->val>=upper) return 0;

        int left = solve(root->left,lower,root->val);
        int right = solve(root->right,root->val,upper);

        return left & right;
    }
    bool isValidBST(TreeNode* root) {

        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};