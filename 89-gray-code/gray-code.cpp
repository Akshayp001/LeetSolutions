class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans= {0,1};
        if(n==1) return ans;
        long long t = 2;
        for(int i=1;i<n;i++){
            int sz= (int)ans.size();
            int ti = pow(t,i);
            for(int i=sz-1;i>=0;i--){
                ans.push_back(ti+ans[i]);
            }
        }
        return ans;        
    }
};