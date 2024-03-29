class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0,j=0;
        while(j<m && i<n){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            if(nums1[i]>nums2[j]) j++;
            else i++; 
        }
        return -1;        
    }
};