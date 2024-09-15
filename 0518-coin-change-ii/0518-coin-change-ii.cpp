class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<int> prev(amount+1,0),curr(amount+1,0);
        int n= coins.size();
        for(int t=0 ;t<=amount ;t++){
            prev[t]=(t%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                int notTake= prev[t];
                int take=0;
                if(coins[ind]<= t){
                    take= curr[t-coins[ind]];
                }
                curr[t]= take+notTake;
            }
            prev= curr;
        }
        
        return prev[amount];
    }
};