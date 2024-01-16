bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});
        vector<pair<int,int>> sol;
        vector<int> ans;

        for(int i=0;i<k;i++){
            sol.push_back(pq.top());
            pq.pop();
        }

        sort(sol.begin(),sol.end(),cmp);
        for(auto &i:sol) ans.push_back(i.first);
        return ans;
    }
};