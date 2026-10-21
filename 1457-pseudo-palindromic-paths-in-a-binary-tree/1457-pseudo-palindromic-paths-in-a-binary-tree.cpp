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
    // bool check(){
    //     int odd=0;
    //     for(int i=0;i<10;i++){
    //         if(freq[i]%2!=0) odd++;
    //     }

    //     return odd<=1;
    // }
    void solve(TreeNode* root,int odd){
        freq[root->val]++;
        if(freq[root->val]%2==0) odd--;
        else odd++;

        if(!root->left && !root->right){
            if(odd<=1){
                total++;
            }
            
            if(freq[root->val]%2==0) odd++;
            else odd--;
            freq[root->val]--;

            return ;
        }

        if(root->left) solve(root->left,odd);
        if(root->right) solve(root->right,odd);

        if(freq[root->val]%2==0) odd++;
        else odd--;
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        freq.assign(10,0);

        solve(root,0);

        return total;
    }
};