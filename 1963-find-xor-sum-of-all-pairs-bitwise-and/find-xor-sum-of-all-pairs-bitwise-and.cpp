class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int bx = 0;
        for(auto &i:arr2) bx^=i;
        int ax = 0;
        for(auto &i:arr1){
            ax = ax ^ i;
        }
        return ax&bx;
    }
};