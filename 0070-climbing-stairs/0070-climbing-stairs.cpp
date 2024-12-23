class Solution {
    int f(int n,vector<int> & dp){
         if(n==0) return 1 ;
        
        if(n==1) return 1;
         if(dp[n]!=-1) return dp[n];
        int left= f(n-1,dp);
        int right= f(n-2,dp);
       
        return dp[n]=left+right;
    }
public:
    int climbStairs(int n) {
      
        
        vector<int> dp(n+1,-1);
        return f(n,dp);
        
    }
};