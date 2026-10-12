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
    ListNode* removeNodes(ListNode* head) {
        head = solve(head,NULL);

        int maxi=head->val;
        ListNode*curr=head->next;
        ListNode*prev=head;

        while(curr){
            if(curr->val<maxi){
                curr = curr->next;
            }
            else{
                maxi = max(maxi,curr->val);
                prev->next=curr;
                prev = curr;
                curr = curr->next;
            }
            
        }
        prev->next=curr;


        return solve(head,NULL);
    }
};