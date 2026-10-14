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

    int n=0;
    ListNode* tail;
    ListNode* tail2;

    Solution(ListNode* head) {
        tail2 = head;
        tail = tail2;

        while(tail){
            n++;
            tail = tail->next;
        }
        
    }
    
    int getRandom() {
        tail = tail2;

        int x = rand() % n;
        
        while(x--){
            tail = tail->next;
        }

        return tail->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */