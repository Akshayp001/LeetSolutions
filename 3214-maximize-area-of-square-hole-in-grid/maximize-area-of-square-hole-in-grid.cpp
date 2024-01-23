class Solution {
public:

    void maxConsecRange(vector<int> &arr,int &maxi){
        int prev = arr[0],count=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]+1) count++, maxi = max(maxi,count);
            else count =1;
            prev= arr[i];                        
        } 
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end()); sort(v.begin(),v.end());
        int hmaxi=1,vmaxi=1;
        maxConsecRange(h,hmaxi); maxConsecRange(v,vmaxi);
        return pow(min(hmaxi,vmaxi)+1,2);             
    }
};