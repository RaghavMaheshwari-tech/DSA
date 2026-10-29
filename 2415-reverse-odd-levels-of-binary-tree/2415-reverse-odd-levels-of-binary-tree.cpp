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
    void swapping(vector<TreeNode*>arr){
        int end = arr.size()-1;
        int start=0;
        while(start<end){
            swap(arr[start]->val,arr[end]->val);
            start++;
            end--;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* head = root;
        int level=0;
        queue<TreeNode*>dq;
        dq.push(root);
        while(!dq.empty()){
            int n = dq.size();
            level++;
            vector<TreeNode*>arr;
            while(n--){
                TreeNode* temp=dq.front();
                dq.pop();
                if(temp->left) {
                    arr.push_back(temp->left);
                    dq.push(temp->left);
                }
                if(temp->right) {
                    arr.push_back(temp->right);
                    dq.push(temp->right);
                }
            }

            if(level%2!=0) swapping(arr);
        }

        return head;
    }
};