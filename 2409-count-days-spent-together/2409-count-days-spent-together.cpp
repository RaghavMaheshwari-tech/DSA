class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>calendar = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        int Alice_incoming_month = stoi(arriveAlice.substr(0,2));
        int Alice_incoming_date = stoi(arriveAlice.substr(3,2));
        int Alice_outgoing_month = stoi(leaveAlice.substr(0,2));
        int Alice_outgoing_date = stoi(leaveAlice.substr(3,2));
        int Bob_incoming_month = stoi(arriveBob.substr(0,2));
        int Bob_incoming_date = stoi(arriveBob.substr(3,2));
        int Bob_outgoing_month = stoi(leaveBob.substr(0,2));
        int Bob_outgoing_date = stoi(leaveBob.substr(3,2));

        int incoming_month=-1,incoming_date=-1;
        if(Alice_incoming_month<Bob_incoming_month){
            incoming_month = Bob_incoming_month;
            incoming_date = Bob_incoming_date;
        }
        else if(Alice_incoming_month>Bob_incoming_month){
            incoming_month = Alice_incoming_month;
            incoming_date = Alice_incoming_date;
        }
        else{
            incoming_month = Alice_incoming_month;
            if(Alice_incoming_date<=Bob_incoming_date){
                incoming_date = Bob_incoming_date;
            }
            else incoming_date = Alice_incoming_date;
        }

        int outgoing_month=-1,outgoing_date=-1;
        if(Alice_outgoing_month<Bob_outgoing_month){
            outgoing_month = Alice_outgoing_month;
            outgoing_date = Alice_outgoing_date;
        }
        else if(Alice_outgoing_month>Bob_outgoing_month){
            outgoing_month = Bob_outgoing_month;
            outgoing_date = Bob_outgoing_date;
        }
        else{
            outgoing_month = Alice_outgoing_month;
            if(Alice_outgoing_date<=Bob_outgoing_date){
                outgoing_date = Alice_outgoing_date;
            }
            else outgoing_date = Bob_outgoing_date;
        }

        if(incoming_month>outgoing_month) return 0;
        else if(incoming_month==outgoing_month){
            if(incoming_date>outgoing_date) return 0;
            else return outgoing_date-incoming_date+1;
        }
        else{
            int ans =0;
            ans = calendar[incoming_month]-incoming_date+1;
            incoming_month++;
            while(incoming_month<outgoing_month){
                ans+=calendar[incoming_month];
                incoming_month++;
            }
            ans+=outgoing_date;
            return ans;
        }

        return -1;






    }
};