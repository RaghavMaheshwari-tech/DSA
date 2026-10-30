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
int total_nodes=0;
    int height(TreeNode* root){
        if(!root) return 0;

        total_nodes++;
        int left = height(root->left);
        int right = height(root->right);

        return 1+max(left,right);
    }
    bool isCompleteTree(TreeNode* root) {
        int h = height(root);

        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            int n = q.size();
            h-=1;
            if(i!=n) return 0;
            total_nodes-=i;
            if(h==1) break;
            
            while(n--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            i*=2;
        }

        while(!q.empty() && total_nodes>0){
            TreeNode* node = q.front();
            q.pop();

            if(total_nodes>=2 && (node->left) && (node->right)){
                total_nodes-=2;
            }
            else if(total_nodes==1 && node->left){
                total_nodes-=1;
            }
            else return 0;
        }

        return 1;

        
    }
};