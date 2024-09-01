class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          int el1=INT_MIN;
        int el2=INT_MIN;
          vector<int> ls;
        int cnt1=0;
        int cnt2=0;
        int n= nums.size();
        if(nums.size()==0) return ls;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
             else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i])cnt1++;
            else if(el2==nums[i])cnt2++;
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        int mini= int(n/3)+1;
        cnt1=0;
        cnt2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
            
        }
      
        if(cnt1>=mini)  ls.push_back(el1);
        if(cnt2>=mini)   ls.push_back(el2);
        
        return ls;
    }
};