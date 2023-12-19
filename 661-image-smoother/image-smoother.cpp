class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n= img.size();
        int m= img[0].size();
        vector<vector<int>> ans= img;

        int delRow[8]={-1,0,1,0,-1,1,1,-1};
        int delCol[8]={0,1,0,-1,1,1,-1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int sum=img[i][j];
                int cnt=1;
                for(int k=0;k<8;k++){
                    int newR= i+delRow[k];
                    int newC= j+delCol[k];

                    if(newR>=0 &&newC>=0 && newR<n && newC<m){
                        sum= sum+img[newR][newC];
                        cnt++;
                    }
                }
                ans[i][j]= floor(sum/cnt);

                

            }
        }

        return ans;
        
    }
};