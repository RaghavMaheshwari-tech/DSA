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
        int cnt=1;

        while(fut){

            int a = curr->val;
            int b = prev->val;
            int c = fut->val;

            if((a>b && a>c) || (a<b && a<c)) arr.push_back(cnt);

            cnt++;
            prev=curr;
            curr=fut;
            fut=fut->next;
        }

        if(arr.size()<2) return {-1,-1};

        int maxi = arr[arr.size()-1]-arr[0];
        int mini = maxi;

        for(int i=1;i<arr.size();i++){
            mini = min(mini,arr[i]-arr[i-1]);
        }

        return {mini,maxi};

    }
};