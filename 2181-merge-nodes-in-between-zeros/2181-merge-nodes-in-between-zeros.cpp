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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = new ListNode(0);
        ListNode* tail = root;

        int sum = 0;

        while(head){
            if(head->val==0) {
                sum=0;
                head = head->next;
            }
            else{
                while(head && head->val!=0){
                    sum+=head->val;
                    head = head->next;
                }
                tail->next=new ListNode(sum);
                tail = tail->next;
            }
        }

        return root->next;
    }
};