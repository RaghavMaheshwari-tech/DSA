class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m+1,0);
        prev[0] = 1;//imp. to write after first one

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){

                if(s[i-1]==t[j-1]) prev[j] = prev[j-1] + prev[j];
            }
        }
        return (int)prev[m];
    }
};