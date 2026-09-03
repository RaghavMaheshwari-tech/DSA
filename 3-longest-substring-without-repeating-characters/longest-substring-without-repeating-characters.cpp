class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start=0,end=0;
        unordered_set<char>st;
        int ans=0;

        while(end<n){

            while(start<end && st.count(s[end])){
                st.erase(s[start]);
                start++;
            }

            st.insert(s[end]);
            ans = max(ans,end-start+1);
            end++;
        }

        return ans;
    }
};