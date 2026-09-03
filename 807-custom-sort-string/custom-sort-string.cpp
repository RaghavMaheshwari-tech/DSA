class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        int n = s.size(), m= order.size();

        for(int i=0;i<n;i++) mp[s[i]]++;

        string ans;

        for(int i=0;i<m;i++){
            while(mp[order[i]]>0){
                ans.push_back(order[i]);
                mp[order[i]]--;
            }
        }

        for(auto [c,freq]:mp){
            while(freq>0){
                ans.push_back(c);
                freq--;
            }
        }

        return ans;
    }
};