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
    //0->left dir
    //1->right dir
    int ans = 0;
    void solve(TreeNode* root, bool old, int step){

        ans = max(ans,step);

        if(old){
            if(root->left) solve(root->left,0,step+1);
            if(root->right) solve(root->right,old,1);
        }
        else{
            if(root->left) solve(root->left,old,1);
            if(root->right) solve(root->right,1,step+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        solve(root,1,0);
        return ans;
    }
};