class Solution {
public:
    int toMins(string s){
        int h = stoi(s.substr(0,2)), m = stoi(s.substr(2,2));
        return (h * 60) + m;
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> m;
        for (auto i : access_times) m[i[0]].push_back(toMins(i[1]));
        
        vector<string> ans;
        for (auto i : m) {
            int count = 0;
            sort(m[i.first].begin(), m[i.first].end());
            for (int j = 2; j < m[i.first].size(); j++) { 
                if ((m[i.first][j] - m[i.first][j - 2]) < 60) count++;  
            }
            cout<<endl;
            if (count) ans.push_back(i.first);
        }
        return ans;        
    }
};
