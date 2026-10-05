class Solution {
public:
    int n, m;

    bool valid(int sec, vector<int>& nums, vector<int>&changeIndices){
        
        vector<int>last(n+1,-1);

        for(int i=0;i<=sec;i++){
            last[changeIndices[i]]=i+1;
        }
        for(int i=1;i<=n;i++){
            if(last[i]==-1) return 0;
        }

        map<int,int>last_mp;
        for(int i=1;i<=n;i++){
            last_mp[last[i]] = i;
        }

        int time=0;
        for(auto &[final_time,idx]:last_mp){
            int required_time = nums[idx-1]+1;
            if(final_time<required_time+time) return 0;

            time+=required_time;
        }

        return 1;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n = nums.size();
        m = changeIndices.size();

        // for(int time=0;time<m;time++){
        //     if(valid(time,nums,changeIndices)){
        //         return time+1;
        //     }
        // }

        int start=0,end=m-1;
        int result=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(valid(mid,nums,changeIndices)){
                result = mid+1;
                end=mid-1;
            }
            else start = mid+1;
        }

        return result;

    }
};