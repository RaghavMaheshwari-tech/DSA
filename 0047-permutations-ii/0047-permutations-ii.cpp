class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void find(vector<bool>&visited, vector<int>&temp, vector<int>&nums){

        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            
            visited[i]=1;
            temp.push_back(nums[i]);
            find(visited,temp,nums);
            visited[i]=0;
            temp.pop_back();
            
            int curr=nums[i];
            while(i+1<n && curr==nums[i+1]) i++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vector<bool>visited(n,0);
        vector<int>temp;
        find(visited,temp,nums);
        return ans;
    }
};