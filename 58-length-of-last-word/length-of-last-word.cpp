class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans,t="";
        for(auto &i:s){
            if(i==' '){
                if(t!="") ans = t,t="";   
            }else t+=i;
        }
        if(t!="") ans = t,t="";
        return ans.length();    
    }
};