class Solution {
public:
    vector<long long> gen(){
        vector<long long> v;
        int cap = sqrt(INT_MAX)+1;
        for(long long i=1;i<=cap;i++) v.push_back(i*i);
        return v;
    }
    vector<long long> sq=gen();

    bool judgeSquareSum(int c) {
        int i=0,j=lower_bound(sq.begin(),sq.end(),c)-sq.begin();
        if(sq[j]==c || c==0) return true; 
        while(i<=j){
            if((sq[i]+sq[j])==c) return true;
            if(c-sq[j]>sq[i]) i++;
            else j--;
        }
        return false;
    }
};