class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,n=s.size(),ans=0;
        unordered_map<char,int>mp;

        while(end<n){
            mp[s[end]]++;
            while(mp[s[end]]>1) {
                mp[s[start]]--;
                start++;
            }

            ans = max(ans,end-start+1);
            end++;
        }

        return ans;
    }
};