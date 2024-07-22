class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        vector<int> uniqs;
        for(auto &i:m) uniqs.push_back(i.first);
        sort(uniqs.begin(),uniqs.end(),[&m](int &a,int &b){
            if(m[a]==m[b]) return a>b;
            return m[a]<m[b];
        });
        vector<int> ans;
        for(auto &i:uniqs){
            for(int j=0;j<m[i];j++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};