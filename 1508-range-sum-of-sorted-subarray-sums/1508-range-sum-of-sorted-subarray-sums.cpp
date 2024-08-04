class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long ans=0;
   
   vector<long long>sums;
      
        
     for(int i=0;i<n;++i){
          long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
          
           
       }
     sort(sums.begin(), sums.end());
        
       
        for (int i = left - 1; i < right; i++) {
            ans += sums[i];
        }
        return static_cast<int>(ans% 1000000007);
    }
};