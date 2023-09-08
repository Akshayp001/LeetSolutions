// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // binary Search Approach
        int h = n;
        int l = 1;
        int badversion;

        while(l<=h){
            int mid = l+(h-l)/2;
            if(isBadVersion(mid)){
                badversion = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return badversion; 


        // //linear Approach - NOT GOOD
        // for(int i=n-1;i>=0;i--){
        //     if(!isBadVersion(i)){
        //         return i+1;
        //     }
        // }
        // return 1
        
    }
};