class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long temp =mass;
        for(auto &i:asteroids){
            if(i>temp) return false;
            else temp+=i;
        }
        return true;
    }
};