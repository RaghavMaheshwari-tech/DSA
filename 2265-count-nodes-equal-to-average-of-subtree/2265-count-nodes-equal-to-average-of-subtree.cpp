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
    unordered_map<TreeNode*,int>mp;
    int ans=0;
    int find(TreeNode* root){

        if(!root) return 0;
        if(!root->left && !root->right){
            mp[root] = 1;
            return 1;
        }

        int left = find(root->left);
        int right= find(root->right);
        
        return mp[root] = 1+left+right;
    }

    int solve(TreeNode* root) {
        if(!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if((root->val+left+right)/mp[root]==root->val) ans++;

        return root->val+left+right;
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root->left && !root->right) return 1;

        find(root);
        solve(root);

        return ans;

    }
};