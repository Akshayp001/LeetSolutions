class Solution {
public:
    bool startsWith(const string& mainStr, const string& prefix) {
        return mainStr.compare(0, prefix.length(), prefix) == 0;
    }

    vector<vector<string>> suggestedProducts(vector<string>& prods, string word) {
        vector<vector<string>> ans;
        priority_queue<string,vector<string>,greater<string>> pq;
        for(auto &i:prods) pq.push(i);
        for(int i=0;i<word.length();i++){
            string query= word.substr(0,i+1);
            vector<string> a;
            while(a.size()<3 && !pq.empty()){
                string str = pq.top(); pq.pop();
                if(startsWith(str,query)){
                    a.push_back(str);
                }
            }
            ans.push_back(a);
            for(auto &i:a) pq.push(i);
        }
        return ans;
    }
};