class Solution {
public:
    int isValid(vector<int>& nums,int mid){
        int split=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum <= mid){
                sum+=nums[i];
            }
            else{
                split++;
                sum= nums[i];
            }
        }
        return split;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            int mid= (low+high)/2;
            
            if(isValid(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};