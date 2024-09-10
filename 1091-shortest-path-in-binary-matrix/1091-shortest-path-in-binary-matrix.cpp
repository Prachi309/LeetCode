class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
        int n = grid.size();
        int m = grid[0].size();

        //  start or end cell is blocked
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
    
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
   
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}}); 
        
        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1; 
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            // If we reached the destination, return the distance
            if (r == n-1 && c == m-1) return dis;
            
            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                
               
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        
        return -1;
    }
};