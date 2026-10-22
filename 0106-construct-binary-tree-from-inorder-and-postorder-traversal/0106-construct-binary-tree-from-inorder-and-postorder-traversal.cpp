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
    TreeNode* solve(int start,int end, int idx, vector<int>&inorder, vector<int>&postorder){

        if(start>end) return NULL;

        TreeNode* root;
        for(int i=start;i<=end;i++){

            if(postorder[idx]==inorder[i]){
                root = new TreeNode(inorder[i]);
                root->right = solve(i+1,end,idx-1,inorder,postorder);
                root->left = solve(start,i-1,idx - (end - i) - 1,inorder,postorder);
                
                break;
            }
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(0,n-1,n-1,inorder,postorder);
    }
};