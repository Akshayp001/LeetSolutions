class DataStream {
    int val;
    int k;
    int ele=0;
public:
    DataStream(int value, int k) {
        this->val = value;
        this->k = k;

        queue<int> q;  
    }
    
    bool consec(int num) {
        if(num==val){
            ele++;
        }else{
            ele=0;
        }
        return ele>=k;    
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */