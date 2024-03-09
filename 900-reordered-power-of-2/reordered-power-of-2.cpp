class Solution {
    unordered_map<string,int> powers;
public:
    Solution(){
        for(int i=0;i<32;i++){
            string t = to_string((long long)pow(2,i));
            sort(t.begin(),t.end());
            powers[t]++;
        }        
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        if(powers[s]>=1) return true;
        return false;
    }
};