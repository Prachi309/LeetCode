class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int zeroes=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes>k){
               if(nums[l]==0){
                zeroes--;
               }
               l++;
                
            }
            if(zeroes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};