class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        int n = s.size();

        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }

        string ans;
        vector<bool>visited(26,0);

        for(int i=0;i<n;i++){

            if(visited[s[i] - 'a'] == 1) continue;

            while(ans.size()>0 && s[i]<ans.back() && mp[ans.back()]>i){
                
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[s[i]-'a']=1;
        }

        return ans;
    }
};