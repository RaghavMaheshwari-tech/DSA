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
        int n = arr.size();
        int cnt=0;
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }

        for(int i=0;i<n;i++){
            if(temp[i]!=arr[i]){
                int ele = arr[i];
                swap(arr[i],arr[mp[temp[i]]]);
                mp[ele] = mp[temp[i]];
                mp[temp[i]] = i;
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