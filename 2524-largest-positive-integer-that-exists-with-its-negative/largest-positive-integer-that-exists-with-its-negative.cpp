class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int mini=0;
        unordered_map<int,int> m;
        for(auto &i:nums){
            mini=min(mini,i);
            m[i]++;
        }
        for(int i=mini;i<0;i++){
            if(m.find(i)==m.end()) continue;
            if(m.find(abs(i))!=m.end()){
                return abs(i);
            }
        }  
        return -1;   
    }
};