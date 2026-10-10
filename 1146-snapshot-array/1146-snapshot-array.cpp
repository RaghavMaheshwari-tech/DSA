class SnapshotArray {
public:
    vector<vector<pair<int,int>> >temp;
    int snap_size;
    SnapshotArray(int length) {
        temp.resize(length);
        for(int i = 0; i < length; i++) {
            temp[i].push_back({0, 0});
        }
        snap_size=0;
    }
    
    void set(int index, int val) {
        if(temp[index].back().first == snap_size){
            temp[index].back().second = val;
        }
        else temp[index].push_back({snap_size,val});
    }
    
    int snap() {
        snap_size++;
        return snap_size-1;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int,int>> &v = temp[index];
        int x = v.size();

        int start = 0;
        int end = x-1;
        int ans=-1;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(v[mid].first<=snap_id){
                ans = mid;
                start=mid+1;
            }
            else end = mid-1;
        }

        if(ans==-1) return 0;
        else return v[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */