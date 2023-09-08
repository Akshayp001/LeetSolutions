// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> ans(2,-1);
//         for(int i=0;i<numbers.size();i++){
//             int a = numbers[i];
//             int b = target-a;
//             int l = 0;
//             int h = numbers.size()-1;

//             while(l<=h){
//                 int mid = (l+h)/2;
//                 cout<<l<<" "<<h<<endl;
//                 if(numbers[mid]==b && mid!=i){
//                     ans[0]=(i+1)<(mid+1)?(i+1):(mid+1);
//                     ans[1]=(i+1)>(mid+1)?(i+1):(mid+1);
//                     return ans;
//                 }
//                 if(numbers[mid]<b){
//                     l = mid+1;
//                 }else{
//                     h = mid-1;
//                 }
//             }
//         }
//         return ans;        
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, -1);
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

