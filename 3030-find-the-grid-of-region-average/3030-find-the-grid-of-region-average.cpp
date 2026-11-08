class Solution {
public:
    vector<vector<vector<int>>>arr;
    int row[2] = {0,-1};
    int col[2] = {-1,0};
    int n,m;

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    void solve(int i, int j, int & threshold,vector<vector<int>>& image){

        bool flag=1;//valid subarray hai ki nahi

        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){

                for(int k=0;k<2;k++){
                    int nr=x+row[k];
                    int nc=y+col[k];

                    if(nr>=i && nc>=j && abs(image[x][y]-image[nr][nc])>threshold){
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }

        if(!flag) return;

        long long sum=0;

        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                sum+=image[x][y];
            }
        }

        sum/=9;

        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                arr[x][y].push_back(sum);
            }
        }

    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {

        n= image.size();
        m = image[0].size();

        arr.assign(n,vector<vector<int>>(m));
        vector<vector<int>>ans = image;

        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                solve(i,j,threshold,image);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j].size()==0) continue;

                int x = arr[i][j].size();
                long long sum=0;

                for(auto val:arr[i][j]){
                    sum+=val;
                }

                sum/=x;
                ans[i][j]=sum;
            }
        }

        return ans;
    }
};