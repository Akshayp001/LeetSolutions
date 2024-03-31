class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt=0;
        int n=nums.size();
        int i=0,j=0;
        vector<pair<int,int>> w;
        while(i<n){
            if(nums[i]>=minK && nums[i]<=maxK){
                while(j<n && nums[j]>=minK && nums[j]<=maxK)
                    j++;
                w.push_back({i,j-1});
                i=j;
            }else i++,j++; 
        }
        for(auto &itr:w){
            int l=itr.first,r=itr.second;
            unordered_map<int,vector<int>> mp;
            for(int i=l;i<=r;i++){
                if(nums[i]==minK)mp[minK].push_back(i);
                else if(nums[i]==maxK) mp[maxK].push_back(i);
            }
            for(int i=l;i<=r;i++){
                auto a=lower_bound(mp[minK].begin(),mp[minK].end(),i);
                auto b=lower_bound(mp[maxK].begin(),mp[maxK].end(),i);
                if(a==mp[minK].end() || b==mp[maxK].end())break;
                cnt+=min((r+1)-*(a),(r+1)-*(b));
            }
        }
        return cnt;
    }
};