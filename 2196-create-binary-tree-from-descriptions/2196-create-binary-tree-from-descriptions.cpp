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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        int n= descriptions.size();

        for(auto vec:descriptions){
            int a = vec[0];
            int b=vec[1];
            int c=vec[2];

            TreeNode *root;
            if(mp.find(a)==mp.end()){
                root = new TreeNode(a);
                TreeNode * temp;

                if(mp.find(b)==mp.end()) temp = new TreeNode(b);
                else temp = mp[b];
                 

                if(c==1) root->left = temp;
                else root->right = temp;

                mp[a] = root;
                mp[b] = temp;
            }
            else{
                root = mp[a];
                TreeNode * temp;
                if(mp.find(b)==mp.end()) temp = new TreeNode(b);
                else temp = mp[b];

                if(c==1) root->left = temp;
                else root->right = temp;

                mp[b] = temp;
            }
        }

        unordered_set<int>st;

        for(int i=0;i<n;i++){
            st.insert(descriptions[i][1]);
        }

        TreeNode* ans;
        for(int i=0;i<n;i++){
            if(st.find(descriptions[i][0])==st.end()){
                ans= mp[descriptions[i][0]];
                break;
            }
        }

        return ans;
    }
};