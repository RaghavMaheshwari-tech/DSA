/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* tree(int start, int end, vector<int>&arr){

        if(start>end) return NULL;

        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = tree(start,mid-1,arr);
        root->right = tree(mid+1,end,arr);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {

        TreeNode* root=NULL;

        if(!head) return root;

        vector<int>arr;
        ListNode* tail=head;

        while(tail){
            arr.push_back(tail->val);
            tail = tail->next;
        }

        return tree(0,arr.size()-1,arr);
    }
};