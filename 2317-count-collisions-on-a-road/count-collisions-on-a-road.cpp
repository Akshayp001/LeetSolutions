class Solution {
public:
    int countCollisions(string d) {
        stack<char> s;
        int ans = 0;
        for(int i=0;i<d.size();i++){
            if(s.empty()){
                if(d[i]!='L') s.push(d[i]);
                continue;            
            }
            if(d[i]=='L'){
                if(s.top()=='R'){
                    ans+=2;
                    s.pop();
                    while(!s.empty() && s.top()=='R'){
                        s.pop();
                        ans++;
                    }
                }else{
                    ans++;
                }
                s.push('S');
            }
            if(d[i]=='S'){
                while(!s.empty() && s.top()=='R') {
                    ans++;
                    s.pop();
                }
                s.push('S');
            }
            if(d[i]=='R') s.push('R');    
        }
        return ans;
        
    }
};