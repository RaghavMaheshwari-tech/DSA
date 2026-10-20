class Solution {
public:
    int josephus(int n, int k){
        if(n==1) return 0;

        int idx = josephus(n-1,k);
        idx = (idx+k)%n;

        return idx;
    }

    int findTheWinner(int n, int k) {
        return josephus(n,k)+1;
    }
};