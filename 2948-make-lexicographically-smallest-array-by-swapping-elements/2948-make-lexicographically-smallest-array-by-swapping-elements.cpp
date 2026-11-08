class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++) arr.push_back({nums[i],i});

        sort(arr.begin(),arr.end());

        int start=0,end=1;

        while(end<n){

            vector<int>temp;

            while(end<n && arr[end].first-arr[end-1].first <= limit){
                temp.push_back(arr[end-1].second);
                end++;
            }
            temp.push_back(arr[end-1].second);

            sort(temp.begin(),temp.end());

            for(int i=0;i<temp.size();i++){
                nums[temp[i]] = arr[start++].first;
            }

            end++;
        }

        return nums;


    }
};