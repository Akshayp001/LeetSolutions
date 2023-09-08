class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream my_stream(s);
        string last;
        while(my_stream>>s){
            last=s;
        }               
        return last.length();
    }
};