class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int  i=0,j=1;
        int count=1;
        while(j<chars.size()){
            if(chars[i]==chars[j]) count++,j++,cout<<chars[i]<<" "<<count<<endl;
            else{
                if(i+1==j){
                    count=0;
                    i++;
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
        if(count>1){
                i++;
                string cnt = to_string(count);
                count=0;
                for(auto &it:cnt){
                    chars[i]=it;
                    i++;
                }
                while(i<chars.size()){
                    chars.erase(chars.begin()+i);
                }
        }
        return chars.size();
    }
};