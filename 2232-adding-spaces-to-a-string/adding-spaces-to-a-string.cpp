class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        int m = s.size();

        string ans;
        int start=0;


        for(int i=0;i<m;i++){
            if(start<n && i==spaces[start]){
                ans.push_back(' ');
                start++;
            }
            ans.push_back(s[i]);
        }

        return ans;
    }
};