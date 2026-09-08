class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children) return -1;
        else{
            int y = money-children;//sbko 1 dediya
            int x = y/7;//children who get exactly 8 after accepting 7
            int z = y%7;//left money
            if(x==0) return 0;//8 bn hi nhi skta
            else if(x>children) return children-1;//8 wale count jada ho gye
            else if(x==children){
                if(z>0) return x-1;
            }
            //kuch hi 8 bnege 
            int left = children-x;
            int left_money = y-x*7;
            if(left==1 && left_money==3) return x-1;
            else return x;
        }

        return -1;
    }
};