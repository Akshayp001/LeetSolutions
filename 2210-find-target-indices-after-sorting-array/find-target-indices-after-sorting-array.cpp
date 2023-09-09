class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> sol;

        int l=0,h = nums.size()-1;
        int index= -1;


        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target){
                index = mid;
                break;
            }

            if(nums[mid]>target){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        if(index!=-1){
            sol.push_back(index);
            int i=index;
            while((i-1)>=0 && nums[i-1]==target){
                sol.push_back(i-1);
                i--;            
            }
            i=index;
            while((i+1)<nums.size() && nums[i+1]==target){
                sol.push_back(i+1);
                i++;    
            }
        }
        sort(sol.begin(),sol.end());
        return sol;  
    }
};