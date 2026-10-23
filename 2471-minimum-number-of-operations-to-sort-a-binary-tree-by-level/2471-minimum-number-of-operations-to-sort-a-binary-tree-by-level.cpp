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
    int solve(vector<int>&arr){
        int cnt=0;
        int n= arr.size();
        for(int i=0;i<n-1;i++){
            int mini = i;
            for(int j=i+1;j<n;j++){
                if(arr[mini]>arr[j]){
                    mini = j;
                }
            }

            if(mini!=i){
                swap(arr[i],arr[mini]);
                cnt++;
            }
        }

        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;

        while(!q.empty()){
            int n = q.size();

            vector<int>arr;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                arr.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans += solve(arr);
        }

        return ans;
    }
};