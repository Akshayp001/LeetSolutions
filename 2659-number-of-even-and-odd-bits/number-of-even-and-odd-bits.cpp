class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<32> a(n);
        int e=0,o=0;
        string str= a.to_string();
        reverse(str.begin(),str.end());
        for(int i=0;i<32;i++){
            if(str[i]=='1'){
                if(i&1) o++;
                else e++;
            }   
        }
        return {e,o};        
    }
};