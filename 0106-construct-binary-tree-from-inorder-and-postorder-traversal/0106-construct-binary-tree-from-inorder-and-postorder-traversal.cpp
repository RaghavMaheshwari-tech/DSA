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
    TreeNode* solve(int start,int end, int &idx, vector<int>&inorder, vector<int>&postorder,unordered_map<int,int>&mp){

        if(start>end) return NULL;

        int i = mp[postorder[idx]];
        TreeNode* root = new TreeNode(inorder[i]);

        idx--;

        root->right = solve(i+1,end,idx,inorder,postorder,mp);
        root->left = solve(start,i-1,idx,inorder,postorder,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int idx=n-1;
        return solve(0,n-1,idx,inorder,postorder,mp);
    }
};