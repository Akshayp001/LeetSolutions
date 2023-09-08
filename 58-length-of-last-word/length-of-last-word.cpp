class Solution {
public:
    int lengthOfLastWord(string s) {
        string word  ="";
        string mword;


        for(int i=0;i<s.length();i++){
            if(isspace(s[i])){
                if(word!="") mword = word;
                word="";
                continue;
            }else{
                word.push_back(s[i]);
            }
        } 
        if(word!="") mword = word;
        return mword.length();                    
        
    }
};