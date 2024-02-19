class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0,n=costs.size(),cnt=0;;
        while(coins>0 && i<n){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
            }else break; i++;
        }
        return cnt;        
    }
};