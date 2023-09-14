class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sol;
        int n2 = nums2.size();
        unordered_map<int,int> ng;
        stack<int> st;
        

        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]){
                ng[nums2[i]] = st.top();
            }
            if(st.empty()){
                ng[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }

        for(auto num:nums1){
            sol.push_back(ng[num]);
        }
    return sol;
    }
};