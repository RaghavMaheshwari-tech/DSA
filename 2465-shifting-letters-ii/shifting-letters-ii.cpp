class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();        
        vector<int>arr(n+1,0);

        for(auto v:shifts){

            int x = (v[2]==0)? -1:1;

            arr[v[0]]+=x;
            arr[v[1]+1]-=x;
        }

        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
        }

        for(int i=0;i<n;i++){
            int net_shift = (arr[i] % 26+26)%26; 
            s[i] = 'a' +(s[i]-'a'+net_shift) % 26;
        }

        return s;
    }
};