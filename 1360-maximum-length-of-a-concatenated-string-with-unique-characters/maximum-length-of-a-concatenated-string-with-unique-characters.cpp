class Solution {
public:
    bool check(unordered_map<char,int> m,string &s){
        for(auto &i:s){
            m[i]++;
            if(m[i]>1) return false;
        }
        return true;        
    }

    unordered_map<char,int> updateMap(unordered_map<char,int> m,string &s){
        for(auto &i:s) m[i]++;
        return m;
    }

    void solve(vector<string>&arr,int ind,unordered_map<char,int> m,int ans,int &sol){
        if(ind>=arr.size()){
            sol = max(ans,sol);
            return ;
        }

        if(check(m,arr[ind])){
            solve(arr,ind+1,updateMap(m,arr[ind]),ans+arr[ind].length(),sol);
        }    
        solve(arr,ind+1,m,ans,sol);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> m;
        int sol = 0;
        solve(arr,0,m,0,sol);
        return sol;       
    }
};