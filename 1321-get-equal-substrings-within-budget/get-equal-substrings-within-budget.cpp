class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start=0,end=0,cost=0,len=0;

        while(end<n){
            cost+=abs(s[end]-t[end]);

            while(cost>maxCost){
                cost-=abs(s[start]-t[start]);
                start++;
            }

            len = max(len,end-start+1);
            end++;
        }

        return len;
    }
};