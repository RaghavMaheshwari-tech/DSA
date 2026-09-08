class SmallestInfiniteSet {
public:
    unordered_set<int>st;
    priority_queue<int, vector<int>, greater<int> >pq;


    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) {
            st.insert(i);
            pq.push(i);
        }
    }
    
    int popSmallest() {
        st.erase(pq.top());
        int element = pq.top();
        pq.pop();
        return element;
    }
    
    void addBack(int num) {
        if(!st.count(num)) {
            st.insert(num);
            pq.push(num);
        }

        return ;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */