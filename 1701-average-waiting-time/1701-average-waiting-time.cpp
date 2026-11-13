class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long sum=0;
        long long val=0;

        for(int i=0;i<n;i++){
            int arrival=customers[i][0];
            int waiting=customers[i][1];

            if(sum<arrival){
                sum = arrival+waiting;
                val+=waiting;
            }
            else{
                sum+=waiting;
                val+=(sum-arrival);
            }
        }

        return (1.0*val)/n;
    }
};