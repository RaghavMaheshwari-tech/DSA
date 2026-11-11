class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for(int i=0;i<n;i++){

            vector<int>arr(m,0);

            for(int j=0;j<m;j++){
                if(matrix[i][j]>0){
                    if(i>0) matrix[i][j] += matrix[i-1][j];
                    arr[j] = matrix[i][j];
                }   
            }

            sort(arr.rbegin(),arr.rend());

            for(int i=0;i<m;i++){
                int base=i+1;
                ans=max(ans,base*arr[i]);
            }
        }

        return ans;
    }
};