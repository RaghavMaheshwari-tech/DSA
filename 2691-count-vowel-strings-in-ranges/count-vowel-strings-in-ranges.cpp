class Solution {
public:
    bool valid(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n,0);

        for(int i=0;i<n;i++){

            string word = words[i];
            if(valid(word[0]) && valid(word[word.size()-1])) prefix[i]=1;
        }

        for(int i=1;i<n;i++) prefix[i]+=prefix[i-1];

        vector<int>ans;

        for(auto q:queries){
            if(q[0]!=0){
                ans.push_back(prefix[q[1]]-prefix[q[0]-1]);
            }
            else ans.push_back(prefix[q[1]]);
        }

        return ans;



    }
};