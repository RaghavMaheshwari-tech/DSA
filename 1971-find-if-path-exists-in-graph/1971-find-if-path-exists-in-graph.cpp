class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int>q;
        q.push(source);
        vector<bool>seen(n,0);
        seen[source] = 1;

        while(!q.empty()){

                int start=q.front();
                q.pop();

                if(start==destination) return 1;

                for(int i=0;i<adj[start].size();i++){
                    int next = adj[start][i];
                    if(seen[next]) continue;

                    if(adj[start][i]==destination) return 1;
                    q.push(next);
                    seen[next]=1;
                }
        }

        return 0;
    }
};