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
    vector<int>freq;
    int total=0;
    bool check(){
        int odd=0;
        for(int i=0;i<10;i++){
            if(freq[i]%2!=0) odd++;
        }

        return odd<=1;
    }
    void solve(TreeNode* root){
        freq[root->val]++;

        if(!root->left && !root->right){
            if(check()){
                total++;
            }
            freq[root->val]--;
            return ;
        }

        if(root->left) solve(root->left);
        if(root->right) solve(root->right);

        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        freq.assign(10,0);

        solve(root);

        return total;
    }
};