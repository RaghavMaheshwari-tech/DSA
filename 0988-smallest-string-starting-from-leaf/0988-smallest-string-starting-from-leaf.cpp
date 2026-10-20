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
    void check(string &temp){
        if(ans.size()==0) {
            ans = temp;
            return;
        }

        int n = ans.size();
        int m = temp.size();
        
        for(int i=0;i<min(n,m);i++){
            if(ans[n-i-1]>temp[m-i-1]){
                ans = temp;
                return;
            }
            if(ans[n-i-1] < temp[m-i-1]){
                return;
            }
        }

        ans = (n>m)? temp:ans;
    }
    void find(TreeNode* root ,string &temp){
        if(!root) return;

        

        if(!root->left && !root->right){
            temp+=('a' + root->val);
            check(temp);
            temp.pop_back();
            return;
        }

        temp+=('a' + root->val);
        
        if(root->left) find(root->left,temp);
        if(root->right) find(root->right,temp);

        temp.pop_back();
        

    }
    string smallestFromLeaf(TreeNode* root) {
        string temp;
        find(root,temp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};