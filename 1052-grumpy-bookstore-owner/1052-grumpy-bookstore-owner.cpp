class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& ans, int k) {
       int sum =0,sum1=0,res=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(ans[i]==0)
            {
                sum+=nums[i];
            }
        }
        int i=0,j=0;
        while(j<nums.size())
        {
            if(ans[j]==1)
            {
                sum1+=nums[j];
            }
            if((j-i+1)<k)
            {
                j++;
            }
            else if((j-i+1)==k)
            {
                res = max(res,sum1);
                if(ans[i]==1)
                {
                    sum1-=nums[i];
                }
                i++;
                j++;
            }
        }
        return sum+res;
    }
};