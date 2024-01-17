// class Solution {
// public:

//     int rotate(vector<int> arr,int k){
//         int n = arr.size();
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             ans+= arr[(k+i)%n]*i;
//         }
//         return ans;
//     }
//     int maxRotateFunction(vector<int>& nums) {
//         int maxi = INT_MIN;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             maxi = max(rotate(nums,i),maxi);
//         }
//         return maxi;  
//     }
// };

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long rotation = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rotation += i * nums[i];
        }

        long long maxi = rotation;
        for (int i = 1; i < n; i++) {
            rotation = rotation + sum - n * nums[n - i];

            maxi = max(maxi, rotation);
        }
        return maxi;
    }
};
