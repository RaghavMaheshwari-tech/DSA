class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>freq(1e5+1,0);
        int n = nums.size();

        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        for(int i=0;i<=1e5;i++){
            if(freq[i]==2){
                ans.push_back(i);
            }
        }

        return ans;
    }
};