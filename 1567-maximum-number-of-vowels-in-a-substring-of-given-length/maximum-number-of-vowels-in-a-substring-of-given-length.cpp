class Solution {
public:
    bool valid(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int start=0,end=0;
        int count=0,ans=0;

        while(end<n){
            if(valid(s[end])) count++;

            if(end-start==k){
                if(valid(s[start])) count--;
                start++;
            }

            if(end-start+1==k) ans= max(ans,count);

            end++;
        }

        return ans;
    }
};