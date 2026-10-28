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

class FindElements {
public:
    TreeNode* head;

    void making(TreeNode* root){

        int value = root->val;
        if(root->left){
            root->left->val = 2*value+1;
            making(root->left);
        }
        if(root->right){
            root->right->val = 2*value+2;
            making(root->right);
        }
    }

    FindElements(TreeNode* root) {
        head=root;
        root->val=0;
        making(root);
    }

    bool check(TreeNode* root, int target){
        if(!root) return 0;
        if(root->val==target) return 1;

        int left=0,right=0;
        right=check(root->right,target);
        left=check(root->left,target);

        return left || right;
    }
    
    bool find(int target) {
        return check(head,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */