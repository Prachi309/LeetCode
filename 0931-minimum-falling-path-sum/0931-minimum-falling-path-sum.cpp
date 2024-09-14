class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        vector<int> prev(m,0),curr(m,0);
        for(int j=0;j<m;j++){
            prev[j]= matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u= matrix[i][j]+ prev[j];
                int ld= matrix[i][j]; 
                int rd= matrix[i][j];
                if(j >0) ld+=prev[j-1];
                else{
                    ld+=1e9;
                }
               
                if(j <m-1) rd+=prev[j+1];
                else{
                    rd+=1e9;
                }
                
                curr[j]=min(u, min(ld,rd));
                
                
            }
            prev= curr;
        }
        
        
        int mini=1e9;
        
        for(int j=0;j<m;j++){
            mini= min(mini, prev[j]);
        }
        
        return mini;
    }
};