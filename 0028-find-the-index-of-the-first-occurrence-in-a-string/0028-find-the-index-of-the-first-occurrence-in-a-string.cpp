class Solution {
public:
    int strStr(string haystack, string needle) {
     
        int n=haystack.size();
        int m= needle.size();
        int i=0;
        while(i<n){
            if(haystack.substr(i,m)==needle){
               return i;
            }
            
           
            else {
                i++;
            }
        }
        return -1;
    }
};