class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int  i=0,j=1;
        int count=1;
        while(j<chars.size() || count>1){
            if(j<chars.size() && chars[i]==chars[j]) count++,j++;
            else{
                if(i+1==j){
                    count=0; i++;
                    continue;
                }
                i++;
                string cnt = to_string(count);
                count=0;
                for(auto &it:cnt){
                    chars[i]=it;
                    i++;
                }
                while(i<j){
                    chars.erase(chars.begin()+i);
                    j--;
                }
            }
        }
        return chars.size();
    }
};