class Solution {
public:
    bool check(int target, vector<vector<int>>& matrix, int k){
        int x=0;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            x += (upper_bound(matrix[i].begin(),matrix[i].end(), target)-matrix[i].begin());
        }

        return x>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int start=matrix[0][0];
        int end = matrix[n-1][n-1];

        int ans=end;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(check(mid,matrix,k)){
                ans = mid;
                end=mid-1;
            }
            else start=mid+1;
        }

        return ans;
    }
};