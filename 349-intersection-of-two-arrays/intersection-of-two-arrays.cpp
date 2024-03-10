class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        vector<int> sol;
        unordered_map<int,int> ump;
        for(int i=0;i<nums1.size();i++){
            int target =nums1[i];
            if(ump[target]<1){
                ump[target]++;
            }else{
                continue;
            }

            int l = 0;
            int h = nums2.size()-1;
            
            while(l<=h){
               int mid = (l+h)/2;
               cout<<mid<<" "<<nums2[mid]<<endl;
                if(target==nums2[mid]){
                    sol.push_back(target);
                    break;
                }
                if(target>nums2[mid]){
                    l = mid+1;
                }else{
                    h = mid-1;
                }
            }

        }

    return sol; 
    }
};