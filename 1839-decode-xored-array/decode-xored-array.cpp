class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans=encoded;
        int n = encoded.size();
        for(int i=0;i<n;i++){
            int t=first;
            first^=ans[i];
            ans[i]=t;
        }
        ans.push_back(first);
        return ans;        
    }
};