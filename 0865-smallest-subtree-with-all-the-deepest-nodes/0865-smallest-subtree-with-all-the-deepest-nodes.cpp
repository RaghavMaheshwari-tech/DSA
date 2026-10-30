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
    unordered_map<TreeNode*,TreeNode*>mp;

    int height(TreeNode*root, TreeNode* par){
        if(!root) return 0;

        mp[root] = par;

        int left = height(root->left,root);
        int right = height(root->right,root);

        return 1+max(left,right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h = height(root,NULL);

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            h-=1;
            if(h==0) break;

            while(n--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        TreeNode* first = q.front();
        TreeNode* last = q.back();

        while(first!=last){
            first = mp[first];
            last = mp[last];
        }

        return first;
    }
};