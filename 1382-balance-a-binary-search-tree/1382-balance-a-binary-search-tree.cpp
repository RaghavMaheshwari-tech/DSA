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
    void triverse(TreeNode* root, vector<TreeNode*> &arr){
        if(!root) return;

        triverse(root->left,arr);
        arr.push_back(root);
        triverse(root->right,arr);
    }
    TreeNode* making(vector<TreeNode*>&arr, int start, int end){
        
        if(start>end){
            return NULL;
        }

        int mid = start + (end-start)/2;
        TreeNode *temp = arr[mid];
        temp->left = making(arr,start, mid-1);
        temp->right = making(arr,mid+1,end);

        return temp;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>arr;
        triverse(root,arr);

        return making(arr,0,arr.size()-1);
    }
};