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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        ListNode* fut = head->next->next;
        ListNode* curr=head->next;
        ListNode* prev=head;
        int first=-1,sec=-1,last=-1;
        int maxi = 0;
        int mini = 1e5;
        int cnt=1;

        while(fut){

            int a = curr->val;
            int b = prev->val;
            int c = fut->val;

            if((a>b && a>c) || (a<b && a<c)){
                if(first==-1){
                    first=cnt;
                    sec=first;
                }
                else{
                    last = cnt;
                    mini = min(mini,last-sec);
                    sec=last;
                }
            }
            cnt++;
            prev=curr;
            curr=fut;
            fut=fut->next;
        }

        if(last==-1) return {-1,-1};

        else return {mini,last-first};

    }
};