class Solution {
public:
    bool isPalindrome(int x) {
        long long num=0;
        long long rem;
        long long temp=x;
       
        while(x>0){
           
            num=num*10+x%10;
            x=x/10;
        }
        if(num==temp){
            return true;
        }
        return false;
    }
};