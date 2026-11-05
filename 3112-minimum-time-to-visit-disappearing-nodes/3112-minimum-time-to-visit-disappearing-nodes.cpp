class Solution {
public:
    typedef long long ll;

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {

        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int wt = edges[i][2];

            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }


        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> >q;

        q.push({0,0});
        vector<int>parent(n,0);
        vector<ll>distance(n,LLONG_MAX);
        distance[0]=0;
        parent[0]=-1;
        vector<int>ans(n,INT_MAX);

        while(!q.empty()){
            auto [time,node] = q.top();
            q.pop();

            if(time >= disappear[node] || ans[node]<time || distance[node]<time) continue;

            ans[node] = time;

            for(int i=0;i<adj[node].size();i++){
                int next_node = adj[node][i].first;
                ll next_weight = distance[node]+adj[node][i].second;

                if(next_node!=parent[node] && distance[next_node]>next_weight){
                    parent[next_node] = node;
                    q.push({next_weight,next_node});
                    distance[next_node] = next_weight;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }

        return ans;
    }
};