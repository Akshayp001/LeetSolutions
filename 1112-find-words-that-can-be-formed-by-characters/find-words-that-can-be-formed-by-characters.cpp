class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m;

        for(auto i:chars){
            m[i]++;
        }

        int ans = 0;
        for(auto word:words){
            int flag=0;
            unordered_map<char,int> m2;

            for(auto lett : word){
                m2[lett]++;
            }

            for(auto i:m2){
                if(m[i.first]<i.second) flag=1;
            }
            cout<<flag<<endl;
            if(!flag) ans+=word.length();
        }
        return ans;
        
    }
};