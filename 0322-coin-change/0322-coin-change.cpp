class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
     vector<int> prev(amount+1,0), curr(amount+1,0);
        int n= nums.size();
        for(int t=0;t<= amount;t++){
            if(t%nums[0]==0){
                prev[t]= t/nums[0];
            }
            else{
                prev[t]=1e9;
            }
        }
        
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int nottake= 0+ prev[t];
                int take=1e9;
                if(nums[ind]<=t){
                    take= 1+curr[t-nums[ind]];
                }
                curr[t]=min(take,nottake);
            }
            prev=curr;
        }
        int ans= prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};