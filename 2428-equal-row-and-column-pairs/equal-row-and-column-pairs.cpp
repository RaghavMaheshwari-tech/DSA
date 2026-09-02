class Solution {
public:
    unordered_map<int,vector<int>>mp;//number,columns
    int n;
    int ans=0;

    void solve(int row, vector<int>arr, vector<vector<int>> &grid){

        for(int i=0;i<arr.size();i++){//itne sab mai (row==col) element
            bool flag = 1;
            for(int j=0;j<n;j++){
                if(grid[row][j]!=grid[j][arr[i]]){
                    flag=0;
                    break;
                }
            }
            if(flag) ans++;
        }

        return ;
    }

    int equalPairs(vector<vector<int>>& grid) {
        n = grid.size();
        
        for(int i=0;i<n;i++){
            mp[grid[0][i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            if(mp.find(grid[i][0])!=mp.end()){
                solve(i,mp[grid[i][0]], grid);
            }
        }

        return ans;
    }
};