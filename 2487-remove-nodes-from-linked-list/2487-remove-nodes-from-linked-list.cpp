// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         if(!head->next) return head;
//         ListNode*tail = head;

//         vector<int>arr;
//         while(tail){
//             arr.push_back(tail->val);
//             tail = tail->next;
//         }

//         int n = arr.size();

//         vector<int>suffix(n);
//         suffix[n-1] = arr[n-1];
//         for(int i=n-2;i>=0;i--){
//             suffix[i] = max(suffix[i+1],arr[i]);
//         }

//         ListNode * root = new ListNode(0);
//         root->next = head;

//         ListNode * prev=root;
//         ListNode* curr = head;

//         int i=0;
//         while(i<n && curr){
//             if(suffix[i]<=arr[i]){
//                 prev=curr;
//                 curr = curr->next;
//             }
//             else{
//                 prev->next = curr->next;
//                 curr = curr->next;
//             }
//             i++;
//         }

//         ListNode * ans = root->next;
//         delete root;
//         return ans;
//     }
// };

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
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        ListNode*tail = head;

        vector<int>arr;
        while(tail){
            arr.push_back(tail->val);
            tail = tail->next;
        }

        int n = arr.size();

        vector<int>suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],arr[i]);
        }

        ListNode * root = new ListNode(0);
        root->next = head;

        ListNode * prev=root;
        ListNode* curr = head;

        int i=0;
        while(curr && i<n){
            while(curr && i<n && suffix[i]<=arr[i]){
                prev=curr;
                curr = curr->next;
                i++;
            }
            while(curr && i<n && suffix[i]>arr[i]){
                prev->next = curr->next;
                curr = curr->next;
                i++;
            }
        }

        return root->next;
    }
};