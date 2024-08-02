class Solution {
public:
    int minSwaps(vector<int>& nums) {
          int n = nums.size();
        int no1s = 0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==1)
           {
             no1s++;
           }
        }
        int lf = 1;
        int rf = no1s-1;
        bool lo = false;
        int nos = n;
        int count = 0;
        for(int i=0;i<no1s;i++)
         {
            if(nums[i]==0)
            {
               count++;
            }
         }
         nos = min(nos,count);
         if(nums[0]==0)
         {
            count--;
         }
         if(no1s<n && nums[no1s]==0)
         {
            count++;
         }
         rf++;
        while(lf<n)
        {
            nos = min(nos,count);
            if(nums[lf]==0)
            {
                count--;
            }
            lf++;
            if(nums[(rf+1)%n]==0)
            {
               count++;
            }
            rf = (rf+1)%n;
        }
        return(nos);
    }
};