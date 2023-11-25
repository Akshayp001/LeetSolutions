
#define fi(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        vector<int> pf;

        int pref = 0;
        for(auto i:nums){
            pref+=i;
            pf.push_back(pref);            
        }
        int n =  nums.size();
        fi(i,n){
            int temp=0;
            int first = nums[i]*(i+1)-pf[i];
            int second =  (pf[pf.size()-1]-pf[i])- nums[i]*(n-i-1);
            cout<<"f s"<<first<<" "<<second<<endl;
            ans.push_back(first+second);
        }
        return ans;

        
    }
};