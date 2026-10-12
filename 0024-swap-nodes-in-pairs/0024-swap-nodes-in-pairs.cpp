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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* root = new ListNode(0);

        ListNode* curr = head;
        ListNode* prev = root;
        ListNode* fut1 = head->next;

        while(fut1 && curr){
            prev->next = fut1;
            curr->next = fut1->next;
            fut1->next = curr;



            prev = curr;
            curr = curr->next;
            if(curr) fut1 = curr->next;
            else fut1 = NULL;
        }

        return root->next;
    }
};