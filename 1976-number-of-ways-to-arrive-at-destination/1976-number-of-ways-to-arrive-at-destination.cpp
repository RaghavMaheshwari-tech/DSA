class Solution {
public:
    typedef long long ll;
    int M = 1e9+7;
    int countPaths(int x, vector<vector<int>>& roads) {
        int n = roads.size();
        vector<vector<pair<int,int>>>adj(x);
        for(int i=0;i<n;i++){
            int a = roads[i][0];
            int b =  roads[i][1];
            int w = roads[i][2];

            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;

        vector<ll>distance(x,LLONG_MAX);
        vector<ll>ways(x,0);

        pq.push({0,0});

        distance[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto [prev_dist,node] = pq.top();
            pq.pop();

            if(prev_dist > distance[node]) continue; 

            for(int i=0;i<adj[node].size();i++){
                int next_node = adj[node][i].first;
                long long int next_dist = 1LL*distance[node]+adj[node][i].second;

                if(distance[next_node]>next_dist){
                    distance[next_node] = next_dist;
                    ways[next_node] = ways[node];
                    pq.push({next_dist,next_node});
                }
                else if(distance[next_node]==next_dist){
                    ways[next_node] = (ways[next_node] + ways[node])%M;
                }
            }
        }

        return ways[x-1];
    }
};