class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int n = piles.size();
        int v = n/3;

        int ans = 0;
        for(int i=0;i<v*2;i++){
            if(i&1) ans+=piles[i];
        }

        return ans;

        
    }
};