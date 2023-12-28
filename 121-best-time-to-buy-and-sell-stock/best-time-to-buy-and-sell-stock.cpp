class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int mini = prices[0];
      int profit = 0;
      for(int i=1;i<prices.size();i++){
            int temp = prices[i]-mini;
            profit = max(profit,temp);
            mini = min(prices[i],mini);
      }
      return profit;
    }

};