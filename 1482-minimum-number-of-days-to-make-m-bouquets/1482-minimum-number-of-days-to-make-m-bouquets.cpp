class Solution {
public:
    bool find(int &target, vector<int>&p, int &m, int &k){
        int count =0;
        int make=0;
        for(int i=0;i<p.size();i++){
            if(p[i]<=target) count++;
            else{
                make += count/k;
                count=0;
            }
        }

        make += count/k;

        return make>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k>n) return -1;
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());

        int ans= -1;

        while(start<=end){
            int mid= start+(end-start)/2;

            if(find(mid,bloomDay,m,k)){
                ans = mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
    }
};