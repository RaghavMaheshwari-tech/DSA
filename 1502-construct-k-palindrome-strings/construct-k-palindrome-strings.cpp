class Solution {
public:
    bool canConstruct(string s, int k) {
        
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }

        int odd=0;

        for(auto it:freq){
            if(it%2!=0) odd++;
        }

        return odd<=k && k<=s.size();
    }
};