class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];
            int wt = roads[i][2];

            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt}); 
        }

        vector<bool>visited(n+1,0);


        
        int ans = INT_MAX;
        queue<int>q;
        q.push(1);
        visited[1]=1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0;i<adj[node].size();i++){
                int next = adj[node][i].first;

                ans = min(ans,adj[node][i].second);

                if(visited[next]==1) continue;

                q.push(next);
                visited[next]=1;
            }
        }

        return ans;
    }
};