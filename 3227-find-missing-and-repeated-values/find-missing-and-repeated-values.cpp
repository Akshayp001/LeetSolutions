class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int x1=0,set=0,ans=0,mis,rep;
        int n = grid.size()*grid[0].size();

        for(auto &r:grid) for(auto &c:r) x1^=c;
        
        for(int i=1;i<=n;i++) x1^=i;
        int t = x1;
        while((t & 1) != 1) {
            set++;
            t >>= 1;
        }
       
        for(auto &j:grid)
            for(auto &i:j) 
                if((i >> set) & 1) 
                    ans ^= i;

        for(int i=1;i<=n;i++)  
            if((i >> set) & 1) 
                ans^=i;

        for(auto &j:grid)
            for(auto &i:j) 
                if(i==ans) return {ans,x1^ans};

        return {x1^ans,ans};   
    }
};