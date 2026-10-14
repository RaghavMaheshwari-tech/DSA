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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        int cnt=0;
        ListNode* prev=NULL;
        ListNode* tail=list1;
        ListNode* temp =list2;
        while(temp->next) temp = temp->next;

        while(tail){
            cnt++;
            prev=tail;
            tail = tail->next;

            if(cnt==a){
                prev->next=list2;
            }

            if(cnt==b+1){
                temp->next = prev->next;
                break;
            }
        }

        return list1;
        
    }
};