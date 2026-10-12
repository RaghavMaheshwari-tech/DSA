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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = solve(head,NULL);
        ListNode* prev=NULL;
        ListNode* curr = head;

        if(n==1) return solve(head->next,NULL);
        
        while(n>1){
            prev = curr;
            curr = curr->next;
            n--;
        }

        prev->next = curr->next;
        delete curr;

        return solve(head,NULL);

        


    }
};