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
    ListNode* doubleIt(ListNode* head) {
        head = solve(head,NULL);
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        int sum=0;

        while(head){
            sum+=2*head->val;
            int rem = sum%10;
            sum/=10;
            tail->next = new ListNode(rem);
            head=head->next;
            tail = tail->next;
        }

        while(sum){
            int rem = sum%10;
            sum/=10;

            tail->next = new ListNode(rem);
            tail = tail->next;
        }

        root = solve(root->next,NULL);

        return root;
    }
};