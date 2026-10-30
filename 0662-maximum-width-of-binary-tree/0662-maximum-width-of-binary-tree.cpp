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
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty()){
            int n = q.size();
            ans = max(ans,q.back().second-q.front().second + 1);

            for(int i=0;i<n;i++){

                TreeNode* temp = q.front().first;
                ll x = q.front().second;
                q.pop();
                if(temp->left) q.push({temp->left,2*x+1});
                if(temp->right) q.push({temp->right,2*x+2});
            }
        }
        return ans;
    }
};