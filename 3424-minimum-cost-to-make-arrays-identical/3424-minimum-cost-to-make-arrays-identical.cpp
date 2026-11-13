class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {

        int n = arr.size();
        long long final=0;

        for(int i=0;i<n;i++){
            final+=(abs(brr[i]-arr[i]));
        }

        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[brr[i]]=arr[i];
        }
        
        long long ans=0;

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        for(int i=0;i<n;i++){
            if(mp[brr[i]]!=arr[i]){
                ans+=k;
                break;
            }
        }

        for(int i=0;i<n;i++){
            ans+=(abs(brr[i]-arr[i]));
        }

        return min(final,ans);
    }
};