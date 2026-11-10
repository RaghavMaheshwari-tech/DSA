class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));

        int val=1;
        int top=0,bottom=n-1,left=0,right=n-1;
        int x=0;
        int final=n*n;

        while(val<=final){

            x=left;
            while(x<=right){
                ans[top][x]=val;
                val++;
                x++;
            }
            top++;

            x=top;
            while(x<=bottom){
                ans[x][right]=val;
                val++;
                x++;
            }
            right--;

            x=right;
            while(x>=left){
                ans[bottom][x]=val;
                val++;
                x--;
            }
            bottom--;

            x=bottom;
            while(x>=top){
                ans[x][left]=val;
                val++;
                x--;
            }
            left++;
        }


        return ans;
    }
};