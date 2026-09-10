class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<ll, vector<ll>, greater<ll>>pq;

        for(int val:nums) pq.push(val);

        int count=0;

        while(pq.top()<k && pq.size()>1){
            count++;
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();

            ll val = (min(x, y) * 2 + max(x, y));
            pq.push(val);
        }

        return count;

    }
};