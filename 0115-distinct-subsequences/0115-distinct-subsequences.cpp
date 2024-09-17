class Solution {
public:
    
//     int f(int i, int j, string s, string t){
//         if(i<0) return 0;
//         if(j<0) return 1;
     
//         if(s[i]==t[j]){
//             return f(i-1,j,s,t)+ f(i-1,j-1,s,t);
//         }
//         else{
//             return f(i-1,j-1,s,t);
//         }
//     }
    
    int numDistinct(string s, string t) {
     
        int n= s.size(),m=t.size();
        vector<double> prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
             prev[j]=prev[j]+prev[j-1];
        }  
            }
        }
        return (int) prev[m];
    }
};