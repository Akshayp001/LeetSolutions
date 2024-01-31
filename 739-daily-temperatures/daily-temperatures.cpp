class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> s;
    int n = temperatures.size()-1;
    vector<int> ans(n+1);

    for(int i=n;i>=0;i--){
        while(!s.empty() && temperatures[s.top()]<=temperatures[i]) s.pop();
        if(s.empty()) ans[i]=0;
        else ans[i] = s.top()-i;  
        s.push(i);
    }
    return ans;
}
};