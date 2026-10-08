class Solution {
public:

    int check(int mid, vector<int>& quant){
        int stores=0;
        for(int i=0;i<quant.size();i++){
            int val = (quant[i]%mid==0)? quant[i]/mid:quant[i]/mid+1;

            stores += val;
        }

        return stores;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1,end=*max_element(quantities.begin(),quantities.end());
        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(check(mid,quantities)<=n){
                ans = mid;
                end = mid-1;
            }
            else start=mid+1;
        }

        return ans;


    }
};