class Solution {
public:

    bool check(int mid, vector<vector<int>>&arr, string &temp, int &k, int &n){
        
        for(int i=n-1;i<n+mid;i++){
            int prev = i - mid;
            int x = arr[i][0] - (prev >= 0 ? arr[prev][0] : 0);
            int y = arr[i][1] - (prev >= 0 ? arr[prev][1] : 0);
            int z = arr[i][2] - (prev >= 0 ? arr[prev][2] : 0);

            if (x >= k && y >= k && z >= k) return 1; 
        }

        return 0;
    }
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;

        int n = s.size();
        int maxi = s.size();
        int mini = k*3;

        vector<vector<int>>arr(2*n,vector<int>(3,0));

        string temp = s+s;
        arr[0][temp[0]-'a']++;

        for(int i=1;i<2*n;i++){
            arr[i] = arr[i-1];
            arr[i][temp[i]-'a']++;
            
        }

        if(arr[n - 1][0] < k || arr[n - 1][1] < k || arr[n - 1][2] < k) return -1;


        int ans=-1;

        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;

            if(check(mid,arr,temp,k,n)){
                ans=mid;
                maxi=mid-1;
            }
            else mini=mid+1;
        }

        return ans;

        
    }
};