class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();

        for(int i=0;i<n;i++){
            q.push(i);
        }
        int cost = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();

            cost++;
            tickets[idx]--;

            if(tickets[idx]>0) q.push(idx);
            if(tickets[k]==0) return cost;
        }

        return cost;
    }
};