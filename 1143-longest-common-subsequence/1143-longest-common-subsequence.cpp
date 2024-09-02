class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); 
        int m = text2.size();  
        

        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        for(int i = 1; i <= n; i++) {
          
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    // If characters match, increment the sequence length by 1
                    curr[j] = 1 + prev[j-1];
                } else {
                    // Otherwise, take the maximum of ignoring either character
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            // Update prev to be the current row for the next iteration
            prev = curr;
        }
        
        // The result is in prev[m] which stores the LCS length
        return prev[m];
    }
};