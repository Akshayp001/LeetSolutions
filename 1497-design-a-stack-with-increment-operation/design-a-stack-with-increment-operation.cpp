class CustomStack {
    int maxSize;
    vector<int> s;
public:
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(s.size()>=maxSize) return;
        s.push_back(x);      
    }
    
    int pop() {
        if(s.size()==0) return -1;
        int t =s.back();
        s.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<s.size();i++){
            s[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */