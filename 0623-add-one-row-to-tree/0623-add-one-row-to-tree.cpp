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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }

        TreeNode* head = root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            if(depth==2) break;

            depth-=1;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
           

            TreeNode* oldLeft = temp->left;
            temp->left = new TreeNode(val);
            temp->left->left = oldLeft;

            TreeNode* oldRight = temp->right;
            temp->right = new TreeNode(val);
            temp->right->right = oldRight;
        }

        return head;
    }
};