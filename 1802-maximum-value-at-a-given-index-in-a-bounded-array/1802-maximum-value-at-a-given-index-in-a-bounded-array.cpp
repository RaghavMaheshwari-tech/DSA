class Solution {
public:
    typedef long long ll;
    bool check(int mid, int i, int n , int limit){
        
        // int start=i-1;
        // int end=i+1;
        // ll sum=mid;
        // ll x=mid;

        // while(start>=0 || end<n){
        //     x = (x-1>0)? x-1:x;
        //     if(start>=0) sum+=x;
        //     if(end<n) sum+=x;

        //     start--;
        //     end++;
        // }

        // return sum<=limit;

        ll sum = mid;
        //right
        //case1 : mid>=right_length
        int x = n-i;//length
        if(mid>=x){
            int y=mid-x;
            sum+=((1LL*mid*(mid+1))/2-(1LL*y*(y+1))/2);
        }
        //case2: mid<right_length , extra 1 add krne padenge
        else{
            int y = n-i-mid;
            sum+=((1LL*mid*(mid+1))/2+y);
        }
        


        //left
        //case1: mid>i
        if(mid>i){
            int y = mid-i-1;
            sum+=((1LL*mid*(mid+1))/2-(1LL*y*(y+1))/2);
        }
        //case2:mid<=i, extra 1 add krne padenge 
        else{
            int y = i-mid+1;
            sum+=((1LL*mid*(mid+1))/2+y);
        }

        sum-=(2*mid);

        return sum<=limit;

    }
    int maxValue(int n, int i, int maxSum) {
        if(n==maxSum) return 1;

        int start=1,end=maxSum;
        int ans = start;

        ll sum = n;
        while(start<=end){
            ll mid = start+(end-start)/2;

            if(check(mid,i,n,maxSum)){
                ans = mid;
                start=mid+1;
            }
            else end= mid-1;
        }

        return ans;

    }
};