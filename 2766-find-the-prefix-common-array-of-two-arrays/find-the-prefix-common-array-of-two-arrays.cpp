class Solution {
public:
    int common(unordered_map<int,int> &a,unordered_map<int,int> &b){
        int cnt=0;
        for(auto &i:a){
            if(b.find(i.first)!=b.end()) cnt++;
        }
        return cnt;
    }
    // vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    //     unordered_map<int,int> a,b;
    //     vector<int> ans;
    //     int n = A.size();
    //     for(int i=0;i<n;i++){
    //         a[A[i]]++;
    //         b[B[i]]++;
    //         ans.push_back(common(a,b));
    //     }
    //     return ans;       
    // }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // bitmask approach
        vector<int> ans;
        bitset<51> a;
        bitset<51> b;
        int n= A.size();
        for(int i=0;i<n;i++){
            a.set(A[i]);
            b.set(B[i]);
            ans.push_back((a&b).count());
        }
        return ans;        
    }
};