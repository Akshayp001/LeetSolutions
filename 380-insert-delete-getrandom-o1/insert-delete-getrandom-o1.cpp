class RandomizedSet {
    set<int> arr;    
public:
    RandomizedSet() {
            
    }
    
    bool insert(int val) {
        if(arr.find(val)==arr.end()){
            arr.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(arr.find(val)==arr.end()){
            return false;
        }
        arr.erase(val);
        return true;
        
    }
    
    int getRandom() {
        int ri = rand()%arr.size();

        auto it = arr.begin();
        advance(it,ri);

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */