class Solution {
public:

    vector<vector<string>>ans;
    int n;
    
    bool valid(string &s){
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(s[start]!=s[end]) return 0;
            else{
                start++;
                end--;
            }
        }
        return 1;
    }

    void solve(int idx, string &s, vector<string>&temp){

        if(idx==n){
            ans.push_back(temp);
            return;
        }

        string curr;
        for(int i=idx;i<n;i++){
            curr+=s[i];
            if(valid(curr)){
                temp.push_back(curr);
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string>temp;
        solve(0,s,temp);
        return ans;
    }
};