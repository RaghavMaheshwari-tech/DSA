class Solution {
public:
    int numberOfSubstrings(string s) {
        int start=0,end=0,n=s.size();

        vector<int>arr(3,0);
        long long  ans =0;

        while(end<n){
                if(s[end]=='a') arr[0]++;
                else if(s[end]=='b') arr[1]++;
                else arr[2]++;

                while(start<end && arr[0]!=0 && arr[1]!=0 && arr[2]!=0){
                    ans += (n-end);
                    arr[s[start]-'a']--;
                    start++;
                }

                end++;
        }

        return ans;
    }
};