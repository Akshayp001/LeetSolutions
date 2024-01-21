

class Solution {
    int m,n;
    map<pair<int,int>,int> mp;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;       
    }
    
    vector<int> flip() {
        int rx=0,ry=0;
        do{
            rx = rand()%m;
            ry = rand()%n;
        }
        while(mp[make_pair(rx,ry)]!=0);
        mp[make_pair(rx,ry)]=1;
        return {rx,ry};        
    }
    
    void reset() {
        mp.clear();        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */