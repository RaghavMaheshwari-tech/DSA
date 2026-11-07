class Solution {
public:

    void solve(int idx, vector<bool> & seen, vector<vector<int>>&adj){
        queue<int>q;
        q.push(idx);
        seen[idx]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int next = adj[node][i];

                if(!seen[next]){
                    seen[next]=1;
                    q.push(next);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<vector<int>>adj(n+1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<bool>seen(n+1,0);
        int ans =0;

        for(int i=1;i<=n;i++){
            if(seen[i]==0){
                ans++;
                solve(i,seen,adj);
            }
        }

        return ans;
    }
};