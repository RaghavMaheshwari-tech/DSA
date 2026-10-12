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
class Solution {
public:

    ListNode* solve(ListNode* curr, ListNode* prev){
        if(!curr) return prev;

        ListNode* fut = curr->next;
        curr->next = prev;

        return solve(fut,curr);
    }
    int pairSum(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev){
            prev->next= NULL;
        }

        ListNode *root = solve(slow,NULL);

        int ans = 0;
        while(root){
            ans = max(ans,root->val+head->val);
            root = root->next;
            head = head->next;
        }

        return ans;

    }
};