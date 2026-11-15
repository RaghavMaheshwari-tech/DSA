class Solution {
public:
    int maximumLength(string s) {
        int n= s.size();
        map<pair<char,int>,int>mp;

        for(int i=0;i<n;i++){
            char ch = s[i];
            int len = 0;

            for(int j=i;j<n;j++){
                if(s[j]==ch){
                    len++;
                    mp[{ch,len}]++;
                }
                else break;
            }
        }

        int ans=0;

        for(auto [key,val]:mp){
            auto &[c,len] = key;

            if(val>=3 && len>ans){
                ans=len;
            }
        }

        return ans==0 ? -1:ans;
    }
};