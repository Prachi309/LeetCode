class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph , int color[], int node, int col){
        color[node]=col;
       for(auto it :graph[node]){
            if(color[it]==-1){
               if(dfs(graph,color,it,!col)==false) return false;
               
            }
            
            else if(color[node]==color[it]) return false;
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        
    int color[n];
         fill(color, color+n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(graph, color, i,0)==false) return false;
            }
        }
        return true;
    }
};