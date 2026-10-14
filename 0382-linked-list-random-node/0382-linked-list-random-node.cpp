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
    vector<int>arr;
    int n;
    Solution(ListNode* head) {
        ListNode* tail = head;

        while(tail){
            arr.push_back(tail->val);
            tail = tail->next;
        }
        n = arr.size();
    }
    
    int getRandom() {
        int x = rand() % n;
        return arr[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */