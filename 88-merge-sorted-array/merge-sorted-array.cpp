class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // for(int i=0;i<nums2.size();i++){
        //     nums1[i+nums1.size()-n]=nums2[i];
        // }
        // sort(nums1.begin(),nums1.end());   

        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(j>-1){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
    }
};