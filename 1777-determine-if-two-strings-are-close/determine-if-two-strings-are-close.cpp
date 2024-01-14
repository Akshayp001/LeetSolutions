class Solution {
public:

    
    bool closeStrings(string word1, string word2) {
        unordered_map<int,int> m,m1;
        vector<int> f1,f2;
        for(auto &i:word1) m[i]++;
        for(auto &i:m) f1.push_back(i.first);
        for(auto &i:word2) m1[i]++;
        for(auto &i:m1) f2.push_back(i.first);
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        if(f1!=f2) return false;
        int k =0;
        for(auto &i:m) f1[k++]=i.second;;
        k=0;
        for(auto &i:m1) f2[k++]=i.second;
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return f1==f2;
    }
};