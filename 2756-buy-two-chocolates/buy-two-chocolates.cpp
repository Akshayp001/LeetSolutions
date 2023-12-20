class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int cnt=0;
        int m = money;
        for(auto price:prices){
            if(cnt==2) return money;
            if(price>money){
                return m;
            }else{
                money -= price;
                cnt++;
            }
        }
        return money;
        
    }
};