class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size();
        int a=0,b=0;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({alice[i]+bob[i],i});
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            int j = arr[i][1];
            if(i&1) b+=bob[j];
            else a+=alice[j];
        }
        return a==b?0:(a>b?1:-1);        
    }
};