class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int t = capacity;
        int n = plants.size();

        for(int i=0;i<n;i++){
            if(plants[i]<=t){
                ans++;
                t-=plants[i];
            }else{
                t = capacity;
                ans= ans+(2*i)+1;
                t-=plants[i];
            }
        }
        return ans;
    }
};