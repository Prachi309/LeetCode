class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
        aheadbuy=aheadnotbuy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            
            currnotbuy=max(prices[ind]+aheadbuy, aheadnotbuy);
            
            currbuy= max(-prices[ind]+aheadnotbuy, aheadbuy);
            
            aheadbuy= currbuy;
            aheadnotbuy=currnotbuy;
            
            
        }
        
        return aheadbuy;
    }
};