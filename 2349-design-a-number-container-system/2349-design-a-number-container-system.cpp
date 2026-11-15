class NumberContainers {
public:
    map<int,set<int>>mp;//yeh val kis kis index mai hai 
    unordered_map<int,int>mp2;//iss index mai kya pda hua hai..
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)!=mp2.end()){
            mp[mp2[index]].erase(index);
        }

        mp2[index]=number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].size()==0) return -1;
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */