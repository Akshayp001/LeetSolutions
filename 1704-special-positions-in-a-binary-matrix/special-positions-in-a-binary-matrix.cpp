class Solution {
public:

    bool check(vector<vector<int>> &mat,int x,int y){
        for(int i=0;i<mat.size();i++){
            if(i==x) continue;
            if(mat[i][y]==1) return false;
        }

        for(int j=0;j<mat[0].size();j++){
            if(y==j) continue;
            if(mat[x][j]==1) return false;
        }

        return true;


    }
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) if(check(mat,i,j)) count++;
            }
        }
        return count;
        
    }
};