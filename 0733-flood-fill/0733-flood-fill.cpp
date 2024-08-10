class Solution {
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans, int iniColor, int color, int delRow[],int delCol[]){
        
        ans[sr][sc]= color;
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++){
            int nrow= sr+delRow[i];
            int ncol= sc+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==iniColor){
                dfs(nrow,ncol,image,ans,iniColor,color, delRow,delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor= image[sr][sc];
        vector<vector<int>> ans= image;
        
        int delRow[]= {-1,0,1,0};
        int delCol[]= {0,+1,0,-1};
        
        dfs(sr,sc,image,ans,iniColor,color, delRow,delCol);
        return ans;
    }
};