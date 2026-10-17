class Solution {
public:
    void solve(int i, string temp, string &digits, vector<string> &ans, vector<string> & arr){

        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }

        string curr = arr[digits[i]-'0'];

        for(int k=0;k<curr.size();k++){
            temp+=curr[k];
            solve(i+1,temp,digits,ans,arr);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string>temp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;
        solve(0,"",digits,ans,temp);

        return ans;
    }
};