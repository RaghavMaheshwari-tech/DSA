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
        int x=0;
        ListNode* tail = head;

        while(tail){
            x++;
            tail = tail->next;
        }

        tail=head;
        int i=1;
        while(i<=x/2){
            tail= tail->next;
            i++;
        }

        ListNode * root = solve(tail,NULL);

        int ans = 0;
        while(root){
            ans = max(ans,root->val+head->val);
            root = root->next;
            head = head->next;
        }

        return ans;

    }
};