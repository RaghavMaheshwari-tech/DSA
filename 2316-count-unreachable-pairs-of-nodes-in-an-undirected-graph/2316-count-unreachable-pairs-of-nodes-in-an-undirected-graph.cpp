class Solution {
public:
    long long solve(int i, unordered_map<int,vector<int>>& adj, vector<bool>&visited){
        queue<int>q;
        q.push(i);
        visited[i]=1;
        long long cnt =0;

        while(!q.empty()){
            cnt++;
            int node = q.front();
            q.pop();

            for(int k=0;k<adj[node].size();k++){
                int next = adj[node][k];
                if(visited[next]) continue;
                
                q.push(next);
                visited[next]=1;
            }
        }

        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,0);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int remainingNodes=n;
        long long ans=0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                long long componentSize = solve(i, adj, visited);
                
                remainingNodes -= componentSize;
                ans += (componentSize * remainingNodes);
            }
        }

        return ans;
    }
};