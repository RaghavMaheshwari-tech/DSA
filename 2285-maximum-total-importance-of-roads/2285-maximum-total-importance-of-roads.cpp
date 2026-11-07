class Solution {
public:
    long long ans=0;

    // void solve(int node, int parent, vector<vector<int>>&adj, vector<int>&arr){

    //     for(int i=0;i<adj[node].size();i++){
    //         int next = adj[node][i];

    //         if(next == parent) continue;

    //         ans += (1LL*arr[node]+arr[next]);
    //         solve(next,node,adj,arr);
    //     }
    // }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indeg(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);

            indeg[a]++;
            indeg[b]++;
        }

        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[indeg[i]].push_back(i);
        }

        int x = 1;
        vector<int>arr(n);
        for(auto [key,vec]:mp){
            for(int val:vec){
                arr[val]=x;
                x++;
            }
        }

        for(int i = 0; i < roads.size(); i++) {
            ans += 1LL * (arr[roads[i][0]] + arr[roads[i][1]]);
        }
        
        return ans;



        
    }
};