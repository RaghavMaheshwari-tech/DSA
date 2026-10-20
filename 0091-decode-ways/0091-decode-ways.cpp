class Solution {
public:
    int n;
    vector<int>dp;

    int find(int idx, string &s){

        if(idx==n) return 1;
        if(s[idx]=='0') return 0;

        if(dp[idx]!=-1) return dp[idx];
        
        string temp;
        
        temp.push_back(s[idx]);
        int left = find(idx+1,s);

        int right = 0;
        if(idx+1<n){
            temp.push_back(s[idx+1]);
            int x = stoi(temp);
            if(x>=10 && x<=26){
                right = find(idx+2,s);
            }
            temp.pop_back();
        }

        temp.pop_back();
        
        return dp[idx] = left+right;
    }
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        if(s.find("00")!=string::npos) return 0;
        n = s.size();
        dp.assign(n+1,-1);
        return find(0,s);
    }
};