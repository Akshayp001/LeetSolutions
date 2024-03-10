class cmp{
    public:
    bool operator()(const vector<int> &a,const vector<int> &b){
        double aa = ((double)(a[0])/a[1]);
        double bb = ((double)(b[0])/b[1]);
        return aa>bb;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({arr[i],arr[j]});
            }
        } k--;
        while(k--){
            pq.pop();
        }  
       return pq.top(); 
    }
};