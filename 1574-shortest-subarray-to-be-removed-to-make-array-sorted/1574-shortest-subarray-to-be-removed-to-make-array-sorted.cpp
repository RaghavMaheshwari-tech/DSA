class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left=0,right=n-1;
        int ans=n;

        while(left<n-1 && arr[left]<=arr[left+1]) left++;
        while(right>0 && arr[right]>=arr[right-1]) right--;

        if(left>right) return 0;
        else{
            ans = min(n-left,right);
            for(int i=0;i<=left;i++){
                int target=arr[i];

                int start=right,end=n-1;
                int x = n;

                while(start<=end){
                    int mid=start+(end-start)/2;

                    if(arr[mid]>=target){
                        x=mid;
                        end=mid-1;
                    }
                    else start=mid+1;
                }

                ans = min(ans,x-i-1);
            }
        }

        return ans;
    }
};