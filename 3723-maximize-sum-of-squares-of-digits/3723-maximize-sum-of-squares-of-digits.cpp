class Solution {
public:
    int M = 2*1e5+1;
    typedef long long ll;
    string maxSumOfSquares(int num, int sum) {
        int max_limit = 9*num;
        if(sum>max_limit) return "";

        string temp;
        ll total = 0;
        int i=9;


        
        while(num--){
            while(i>0 && (total + i > sum)) i--;
            total+=i;
            temp+=to_string(i);
        }

        return temp;

    }
};