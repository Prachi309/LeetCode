class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0), curr(n+1,0);
         for (int ind = n-1; ind >= 0; ind--) {
            for (int prev = ind-1; prev >= -1; prev--) {
                // Case 1: We do not take the current element
                int len = 0 + next[prev + 1];
                
                // Case 2: We take the current element if it forms an increasing subsequence
                if (prev == -1 || nums[ind] > nums[prev]) {
                    len = max(len, 1 + next[ind + 1]);
                }
                
                curr[prev + 1] = len;
            }
      
            next=curr;
        }
        return next[0];
    }
};