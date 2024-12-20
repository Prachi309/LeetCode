class Solution {
public:
   typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll curSum = 0, counter = 0, ans = 0;
        unordered_map<int, int> map;
        int i = 0, j = 0;
        while(j < k - 1) {
            curSum += nums[j];
            if(map[nums[j]] == 0)
                counter++;
            map[nums[j]] = map[nums[j]] + 1;
            j++;
        }
        while(j < n) {
            curSum += nums[j];
            if(map[nums[j]]++ == 0)
                counter++;
            if(counter == k) {
                ans = max(ans, curSum);
            }
            curSum -= nums[i];
            if(map[nums[i]] == 1)
                counter--;
            map[nums[i]] = map[nums[i]] - 1;
            i++; j++;
        }
        return ans;
    }
};