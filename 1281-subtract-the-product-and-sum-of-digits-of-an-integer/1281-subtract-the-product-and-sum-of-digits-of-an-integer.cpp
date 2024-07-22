class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sum=0;
        int prod=1;
        
        while( n!=0){
           int m=n%10;
            sum=sum+m;
            prod=prod*m;
            n=n/10;
        }
        int ans=prod-sum;
        return ans;
    }
};