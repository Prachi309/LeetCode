class Solution {
public:
    
     int lcs(int n, int m, string s, string t) {
        // your code here
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++){
            prev[j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else{
                    curr[j]= max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    
    int longestPalindromeSubseq(string s) {
        string s1= s;
        reverse(s1.begin(),s1.end());
        return lcs(s.size(),s1.size(),s,s1);
    }
};