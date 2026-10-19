class Solution {
public:
    vector<int>freq;
    
    bool check(string &temp){

        vector<int>visited = freq;
        
        for(int j=0;j<temp.size();j++){
            visited[temp[j]-'a']++;
            if(visited[temp[j]-'a']>1) return 0;
        }

        freq = visited;

        return 1;
    }
    int solve(int i,vector<string>& arr){

        if(i==arr.size()) return 0;

        //not take it
        int n_take = solve(i+1,arr);
        //take it
        int take = 0;
        if(check(arr[i])) {
            take = arr[i].size() + solve(i+1,arr);

            for(int j=0;j<arr[i].size();j++){
                freq[arr[i][j]-'a']=0;
            }
        }
        else take = solve(i+1,arr);

        return max(take,n_take);

    }
    int maxLength(vector<string>& arr) {
        freq.assign(26,0);
        return solve(0,arr);
    }
};