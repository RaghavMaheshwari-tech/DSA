class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        vector<string>ans;

        int i=1;
        int end = target[size-1];
        int start=0;

        while(start<size && i<=end){
            if(i!=target[start]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else{
                ans.push_back("Push");
                start++;
            }

            i++;
        }

        return ans;
        
    }
};