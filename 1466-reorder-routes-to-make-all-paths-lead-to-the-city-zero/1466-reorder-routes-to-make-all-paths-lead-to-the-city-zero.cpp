class Solution {
public:
    int ans = 0;

    void solve(int idx, int parent, vector<vector<int>>& outgoing, vector<vector<int>>&incoming){

        for(int i=0;i<outgoing[idx].size();i++){
            if(parent==outgoing[idx][i]) continue;
            ans++;
            solve(outgoing[idx][i],idx,outgoing,incoming);
        }

        for(int i=0;i<incoming[idx].size();i++){
            if(parent==incoming[idx][i]) continue;
            solve(incoming[idx][i],idx,outgoing,incoming);
        }

    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>outgoing(n),incoming(n);

        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];

            outgoing[a].push_back(b);
            incoming[b].push_back(a);
        }

        solve(0,-1,outgoing,incoming);

        return ans;
    }
};