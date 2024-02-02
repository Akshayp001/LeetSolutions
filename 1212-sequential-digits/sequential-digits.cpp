class Solution {
public:
    
    vector<int> res(){
        vector<int> v;
        for(int i=1;i<9;i++){
            int num=i;
            for(int j=i+1;j<=9;j++){
                num = num*10 +j;
                v.push_back(num);
            }  
            sort(v.begin(),v.end());
        }
        return v;
    }
    vector<int> seqDigits=res();

    vector<int> sequentialDigits(int low, int high) {
        int li = lower_bound(seqDigits.begin(),seqDigits.end(),low)-seqDigits.begin();
        int hi = upper_bound(seqDigits.begin(),seqDigits.end(),high)-seqDigits.begin();
        vector<int> ans(seqDigits.begin()+li,seqDigits.begin()+hi);
        return ans;
    }
};