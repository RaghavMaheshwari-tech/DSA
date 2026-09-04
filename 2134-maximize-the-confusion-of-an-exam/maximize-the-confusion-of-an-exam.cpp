class Solution {
public:
    int n;
    int ans=0;

    void solve(char v, string& answerKey, int &k){

        int start=0,end=0,odd=0;

        while(end<n){

            if(answerKey[end]!=v) odd++;

            while(odd>k){
                if(answerKey[start]!=v) odd--;
                start++;
            }

            ans = max(ans,end-start+1);
            end++;
        }
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.size();
        solve('T',answerKey,k);
        solve('F',answerKey,k);

        return ans;

    }
};