class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;

        for (int len = 2; len <= 9; len++) {
            
            for (int start = 0; start <= 9 - len; start++) {
                
                string temp = digits.substr(start, len);
                int val = stoi(temp);

                if (val >= low && val <= high) {
                    ans.push_back(val);
                }
            }
        }

        return ans;
    }
};