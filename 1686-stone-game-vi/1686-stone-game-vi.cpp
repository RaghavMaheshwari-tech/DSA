class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int,pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }

        int alice=0;
        int bob=0;

        int i=0;
        while(!pq.empty()){
            if(i%2==0){
                alice+=pq.top().second.first;
            }
            else bob+=pq.top().second.second;

            pq.pop();
            i++;
        }

        if(alice==bob) return 0;
        else if(alice>bob) return 1;

        return -1;
    }
};