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
    string ans;
    void check(string temp){
        reverse(temp.begin(),temp.end());

        if(ans.size()==0) ans = temp;
        else{
            if(ans>temp){
                ans = temp;
            }
        }
    }
    void find(TreeNode* root ,string &temp){
        if(!root->left && !root->right){
            temp+=('a' + root->val);
            check(temp);
            temp.pop_back();
            return;
        }
        if(!root) return;


        temp+=('a' + root->val);

        if(root->left) find(root->left,temp);
        if(root->right) find(root->right,temp);

        temp.pop_back();
        

    }
    string smallestFromLeaf(TreeNode* root) {
        string temp;
        find(root,temp);
        return ans;
    }
};