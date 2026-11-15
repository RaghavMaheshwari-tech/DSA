class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        vector<vector<int>>dp(26,vector<int>(n+1,0));

        for(int i=0;i<n;i++){
            char ch=s[i];
            int len=0;
            while(i<n){
                if(s[i]==ch){
                    len++;
                    dp[ch-'a'][len]++;
                }
                else break;

                i++;
            }
            i--;
        }

        int ans =0;

        for(int i=0;i<26;i++){
            int sum=0;
            for(int j=n;j>=1;j--){
                sum+=dp[i][j];
                if(sum>=3){
                    ans=max(ans,j);
                    break;
                }
            }
        }

        return ans==0? -1:ans;
    }
};