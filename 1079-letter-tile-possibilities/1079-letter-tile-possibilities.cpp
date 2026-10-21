class Solution {
public:
    int total;
    void solve(vector<int>&freq){
        total++;

        for(int i=0;i<26;i++){

            if(freq[i]>0){
                freq[i]--;
                solve(freq);
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        total=0;
        vector<int>freq(26,0);
        for(char c:tiles){
            freq[c-'A']++;
        }

        solve(freq);

        return total-1;
    }
};