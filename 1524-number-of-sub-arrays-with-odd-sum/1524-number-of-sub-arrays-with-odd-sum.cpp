class Solution {
public:
    typedef long long ll;
    int M=1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd=0;
        int even=1;

        long long sum=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                even++;
                ans+=odd;
            }
            else{
                odd++;
                ans+=even;
            }
        }

        return ans%M;
    }
};