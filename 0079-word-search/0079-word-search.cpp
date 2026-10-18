class Solution {
public:
    int n,m;
    int row[4] = {1,0,0,-1};
    int col[4] = {0,-1,1,0};

    bool valid(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool solve(int r,int c, int y, vector<vector<char>>& board, string &word, vector<vector<bool>> &visited){

        if(y==word.size()) return 1;

        visited[r][c]=1;

        for(int k=0;k<4;k++){
            int nr=r+row[k];
            int nc=c+col[k];

            if(valid(nr,nc) && !visited[nr][nc] && board[nr][nc]==word[y]){
                if(solve(nr,nc,y+1,board,word,visited)) return 1;
            }
        }
        visited[r][c] = 0;

        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(solve(i,j,1,board,word,visited)){
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};