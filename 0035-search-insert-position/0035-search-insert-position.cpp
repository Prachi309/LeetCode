class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
          int low = 0;
        int N= nums.size();
        int high = N - 1;
        int ans = N;  // If k is larger than all elements, it should be inserted at the end
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] > target) {
                ans = mid;  
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans; 
    }
};