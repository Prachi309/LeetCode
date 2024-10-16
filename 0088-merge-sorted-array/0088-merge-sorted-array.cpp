class Solution {
    
    void swapIfNeeded(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);  // Initial gap
        
        while (gap > 0) {
            int left = 0, right = gap;
            
            while (right < len) {
                // Compare elements in nums1
                if (left < m && right < m) {
                    swapIfNeeded(nums1, nums1, left, right);
                }
                // Compare elements between nums1 and nums2
                else if (left < m && right >= m) {
                    swapIfNeeded(nums1, nums2, left, right - m);
                }
                // Compare elements in nums2
                else if (left >= m) {
                    swapIfNeeded(nums2, nums2, left - m, right - m);
                }
                
                left++;
                right++;
            }
            
            // Recalculate gap
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // Copy nums2 back to nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        }
    
};