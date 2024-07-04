class Solution {
public:
    int longestPalindrome(string s) {
        int cnt=0;
        int n=s.size();
        int oddcount=0;
       vector<int> hash(52, 0);
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                hash[c - 'a']++;
            } else if(c >= 'A' && c <= 'Z') {
                hash[c - 'A' + 26]++;
            }
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]%2==0){
                cnt+=hash[i];
            }
            else if(hash[i]>0 && hash[i]%2 !=0){
                cnt=cnt+hash[i]-1;
                oddcount=1;
            }
        }
        
        return cnt+oddcount;
    }
};