class Solution {
    int dfs(int node, int col, vector<vector<int>>& graph , int color[]){
        color[node]=col;
        
        for(auto it : graph[node]){
            if(color[it]==-1){
                if(dfs(it,!col,graph,color)==false) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
      
        int color[n];
        fill(color, color+n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false) return false;
            }
        }
        return true;
    }
};