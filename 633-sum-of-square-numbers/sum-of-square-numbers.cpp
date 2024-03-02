class Solution {
public:
    vector<long long> gen(){
        vector<long long> v;
        int cap = sqrt(INT_MAX)+1;
        for(int i=1;i<=cap;i++){
            long long t=i;
            v.push_back(t*i);
        }
        return v;
    }
    vector<long long> sq=gen();

    bool judgeSquareSum(int c) {
        if(c==0) return true;
        int i=0,j=lower_bound(sq.begin(),sq.end(),c)-sq.begin();
        cout<<sq[sq.size()-1]<<endl;
        if(sq[j]==c) return true;
        j--;
        while(i<=j){
            if((long long)(sq[i]+sq[j])==c) return true;
            if(c-sq[j]>sq[i]) i++;
            else j--;
        }
        return false;
    }
};