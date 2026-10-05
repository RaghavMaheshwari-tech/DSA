class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int start=0;
        int end=n*m-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            int r= mid/m;
            int c=mid%m;

            if(matrix[r][c]==target) return 1;
            else if(matrix[r][c]<target) start = mid+1;
            else end = mid-1;
        }

        return 0;
    }
};