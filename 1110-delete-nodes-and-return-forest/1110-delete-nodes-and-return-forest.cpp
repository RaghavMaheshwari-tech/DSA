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
    vector<TreeNode*>ans;
    queue<TreeNode*>q;
    unordered_set<int>st;
    TreeNode* solve(TreeNode*root){

        if(!root) return NULL;
        if(st.find(root->val)!=st.end()){
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            return NULL;
        }

        root->left = solve(root->left);
        root->right = solve(root->right);

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int val:to_delete) st.insert(val);

        q.push(root);
        int i=0;

        while(!q.empty()){

            if(solve(q.front())) ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};