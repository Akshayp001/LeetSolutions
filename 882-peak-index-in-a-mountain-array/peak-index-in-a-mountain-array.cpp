class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int maxind=-1;
        for(int i=0;i<arr.size();i++){
            if(maxi<arr[i]){
                maxi = arr[i];
                maxind = i;
            }
        }
        return maxind;
        
    }
};