class Solution {
public:

    

    int dfs(int node,int k, int parent, unordered_map<int,vector<int>>& mp){

        if(k<0) return 0;

        int ans = 0;

        for(int i=0;i<mp[node].size();i++){
            if(mp[node][i]==parent) continue;
            ans += dfs(mp[node][i],k-1,node,mp);
        }

        return ans + 1;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>>mp1,mp2;

        for(int i=0;i<edges1.size();i++){
            int a = edges1[i][0];
            int b = edges1[i][1];

            mp1[a].push_back(b);
            mp1[b].push_back(a);
        }
        for(int i=0;i<edges2.size();i++){
            int a = edges2[i][0];
            int b = edges2[i][1];

            mp2[a].push_back(b);
            mp2[b].push_back(a);
        }

        int n = edges1.size()+1;
        int m = edges2.size()+1;

        int maxi = 0;

        for(int i=0;i<m;i++){
            maxi = max(maxi,dfs(i,k-1,-1,mp2));
        }

        vector<int>ans(n,maxi);


        for(int i=0;i<n;i++){
            ans[i]+=dfs(i,k,-1,mp1);
        }

        return ans;


    }
};