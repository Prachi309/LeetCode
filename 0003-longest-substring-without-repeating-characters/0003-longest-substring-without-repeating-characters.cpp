class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
      if(n==0){
        return 0;
      }
      int maxi=INT_MIN;
      unordered_set<int>set;
      int l=0;
      for(int r=0;r<n;r++){
       if( set.find(s[r])!=set.end()  ){
         while (l < r && set.find(s[r]) != set.end()) {
        set.erase(s[l]);
        l++;
         }
       }
       set.insert(s[r]);
       maxi=max(maxi,r-l+1);

      }
      return maxi;
        
            

        
    }
};