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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* tail = head;
        int n = 0;
        while(tail){
            n++;
            tail = tail->next;
        }

        int base = n/k;
        int extra = n%k;

        vector<ListNode*>ans(k,NULL);
        tail=head;

        for(int i=0;i<k;i++){
            ans[i] = tail;
            
            ListNode* prev = NULL;

            int total = base + (extra>0 ? 1:0);
            extra--;

            while(total--){
                prev=tail;
                tail=tail->next;
            }

            if(prev) prev->next=NULL;
        }

        return ans;
    }
};