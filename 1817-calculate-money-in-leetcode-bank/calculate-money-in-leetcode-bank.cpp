class Solution {
public:
    int totalMoney(int n) {
        int comp = n / 7;
        int rem = n % 7;
        int ans = 0;
        for(int i=0;i<comp;i++) ans += 28+(7*i); // Add complete weeks
        ans+= comp*rem + (rem*(rem+1))/2; // Add incomplete days
        return ans; 
    }
};