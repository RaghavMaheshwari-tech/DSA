class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = difficulty.size();
        
        vector<pair<int,int>>arr(n);

        for(int i=0;i<n;i++){
            arr[i] = {difficulty[i],profit[i]};
        }
        sort(arr.begin(),arr.end());

        for(int i=1;i<n;i++){
            arr[i].second = max(arr[i].second,arr[i-1].second);
        }

        unordered_map<int,int>mp;
        for(auto & [diff,pro]:arr){
            mp[diff] = pro;
        }

        sort(difficulty.begin(),difficulty.end());
        int total=0;

        for(int i=0;i<worker.size();i++){
            int target=worker[i];

            int start=0,end=n-1;
            int x = -1;

            while(start<=end){
                int mid=start+(end-start)/2;
                if(difficulty[mid]<=target){
                    x = mid;
                    start=mid+1;
                }
                else end=mid-1;
            }

            if(x!=-1)  total+=mp[difficulty[x]];
        }

        return total;


    }
};