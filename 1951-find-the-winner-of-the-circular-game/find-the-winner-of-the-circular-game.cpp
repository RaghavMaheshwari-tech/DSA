class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;

        for(int i=1;i<=n;i++) q.push(i);

        while(q.size()>1){
            int x = q.size();
            int y = (k-1)%x;

            while(y>0 && y--){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};