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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next = head;
        long long sum=0;
        unordered_map<int,ListNode*>mp;
        mp[0] = root;

        while(head){
            sum+=head->val;

            if(mp.find(sum)!=mp.end()){

                ListNode* start = mp[sum];
                ListNode* temp = start;

                int prevsum=sum;

                while(temp!=head){
                    temp=temp->next;
                    prevsum+=temp->val;
                    
                    if(temp!=head) mp.erase(prevsum);
                }

                start->next = head->next;
                
            }
            else{
                mp[sum] = head;
            }

            head = head->next;

        }

        return root->next;
     
    }
};