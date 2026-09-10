class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int>ans(n);
        sort(deck.begin(),deck.end());

        queue<int>q;
        for(int i=0;i<n;i++) q.push(i);
        int x=0;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            ans[idx] = deck[x++];

            q.push(q.front());
            q.pop();
        }

        return ans;
    }
};