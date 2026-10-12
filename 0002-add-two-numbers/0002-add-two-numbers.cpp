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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = solve(l1,NULL);
        // l2 = solve(l2,NULL);
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        int sum=0;

        while(l1 && l2){
            sum += l1->val+l2->val;
            int rem = sum%10;
            sum/=10;
            tail->next = new ListNode(rem);
            l1=l1->next;
            l2=l2->next;
            tail = tail->next;
        }
        while(l1){
            sum+=l1->val;
            int rem = sum%10;
            sum/=10;
            tail->next = new ListNode(rem);
            l1=l1->next;
            tail = tail->next;
        }
        while(l2){
            sum+=l2->val;
            int rem = sum%10;
            sum/=10;
            tail->next = new ListNode(rem);
            l2=l2->next;
            tail = tail->next;
        }

        while(sum){
            int rem = sum%10;
            sum/=10;

            tail->next = new ListNode(rem);
            tail = tail->next;
        }

        // while(root->next && root->val==0){
        //     root = root->next;
        // }

        // ListNode * ans = solve(root,NULL);

        return root->next;
    }
};