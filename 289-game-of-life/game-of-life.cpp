class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ways = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int n=board.size(),m=board[0].size();
        vector<vector<int>> cnts(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(auto &k:ways){
                    int x =i+k[0],y=j+k[1];
                    if(x>=0 && x<n && y>=0 && y<m) if(board[x][y]==1) cnts[i][j]++;  
                }
            
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]==1){
                    if(cnts[i][j]>3 || cnts[i][j]<2) board[i][j]=0; 
                }else{
                    if(cnts[i][j]==3) board[i][j]=1; 
                } 
    }
};